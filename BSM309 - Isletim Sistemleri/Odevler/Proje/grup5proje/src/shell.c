#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <termios.h>
#include <sys/wait.h>

#define KOMUT_BOYUTU 512
char komutlar[96][512];

void AltSatirKarakteriAt(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '\n')
			str[i] = '\0';
    }
}

void child_handler(int sig){
    pid_t pid;
    int status;
	
    /* Yok et */
    while((pid = waitpid(-1, &status, WNOHANG)) > 0) {}
}

void diziyi_temizle(char* array[3][8]){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 8; j++)
            array[i][j] = NULL;
}

void dosya_oku(char *dosya){
    FILE *fp = fopen(dosya, "r");
    if (fp == NULL){
        perror("Dosya acilamiyor!");
        exit(1);
    }
    
    char line[512];
    int i = 0;
    while(fgets(line, sizeof(line), fp) != NULL){
		for(int i = 0; line[i]; i++){
    	    if(line[i+1] == '\n')
				line[i] = ' '; 	        
    	}
        strcpy(komutlar[i], line);
        i++;
    }
    strcpy(line, "NULL");
    strcpy(komutlar[i], line);
    fclose(fp);
}

int main(int argc, char *argv[]){
    char *komut = NULL;
    char *parcalanmis_komut[3][8];
    int kacinci_komut;
    int wStatus;
    size_t n = KOMUT_BOYUTU;
    char *input = NULL;
    int getline_return_value = 0;
    int noktali_virgul_sayisi;
    bool arkaPlan = false;
    bool devam = true;
    bool eszamanlilik;
    bool dosya_acilacak_mi = false;
    FILE *fp;
	struct termios t;
	tcgetattr(0,&t);
	t.c_cc[VINTR] = 4; // ^D
	tcsetattr(0,TCSANOW,&t);
    
    if(argc == 2){ // Dosya adı girilmişse 
		dosya_oku(argv[1]);
		dosya_acilacak_mi = true;
    }
    
    // Arka plandaki programı yok etmek için
    struct sigaction sa;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = child_handler;
    sigaction(SIGCHLD, &sa, NULL);
    
    int txt_komut_sayaci = 0;
    while(devam)
    {
        noktali_virgul_sayisi = 0;
        eszamanlilik = false;
        kacinci_komut = 0;
        diziyi_temizle(parcalanmis_komut);
    
    	if(dosya_acilacak_mi){
    	    if(strcmp(komutlar[txt_komut_sayaci], "NULL") != 0) {
				input = komutlar[txt_komut_sayaci];	
    	        printf("isletilen komut -> %s", input);
    	        txt_komut_sayaci++;
				if(strcmp(input,"quit")==0)
					kill(0, SIGKILL);
    	    }
    	    else{
    	        dosya_acilacak_mi = false;
    	        txt_komut_sayaci = 0;
    	        continue;
    	    }
    	}
    	else{
			printf("=> ");
			fflush(stdout);
			getline_return_value = getline(&input, &n, stdin);
    	}
		
		AltSatirKarakteriAt(input);
        
    	for(int i = 0; input[i]; i++){ // ls ;;; ; ps gibi inputlar için
    	    if(input[i] == ';' && input[i+1] == ';')
    	        input[i] = ' ';
    	}
    	
    	if(getline_return_value > KOMUT_BOYUTU){ // Karakter sayısı kontrolü
			fprintf(stderr, "Komut siniri asildi! (MAX 512)\n");
			continue;
    	}
		
    	if(strcmp(input, "quit") == 0) // quit
    	    break;
			
    	int i = 0;
    	for(komut = strtok(input, " "); komut != NULL; komut = strtok(NULL, " ")){
    	    if(strcmp(komut, "&") == 0) { // Arka planda çalıştır
    	        arkaPlan = true;
    	        continue;
    	    }
    	    if(strcmp(komut, ";") == 0) { // eşzamanlı çalıştır
    	        parcalanmis_komut[kacinci_komut][i] = NULL;
    	        eszamanlilik = true;
    	        noktali_virgul_sayisi++;
    	        kacinci_komut++;
    	        i = 0;
				continue;
    	    }
			parcalanmis_komut[kacinci_komut][i] = komut;
			i++;
    	}
		parcalanmis_komut[kacinci_komut][i] = NULL;
		
    	if(!eszamanlilik){
			int pid = fork();
			if(pid < 0) {fprintf(stderr, "Fork hatasi!\n");}	
			else if(pid == 0){
				if(strcmp(input, "quit") == 0 || strcmp(parcalanmis_komut[0][0],"quit")==0) // quit
					kill(pid, SIGKILL);	
				execvp(parcalanmis_komut[0][0], parcalanmis_komut[0]);
				perror("Komut yok veya yürütülemez!\n");
				exit(1);
			}	
			else{
				if(!arkaPlan)
					waitpid(pid, &wStatus, 0);
				else 
					arkaPlan = false;
			}
		}
		else{
			for(int i = 0; i < noktali_virgul_sayisi + 1; i++ ){
				int pid = fork();
				if(pid < 0) {fprintf(stderr, "Fork hatasi!\n");}
				else if(pid == 0){ // Child
					if(strcmp(parcalanmis_komut[i][0],"quit")==0)
						kill(pid, SIGKILL);
					execvp(parcalanmis_komut[i][0], parcalanmis_komut[i]);
					perror("Komut yok veya yürütülemez!\n");
				}
			}
    	}
    }
    return 0;
}