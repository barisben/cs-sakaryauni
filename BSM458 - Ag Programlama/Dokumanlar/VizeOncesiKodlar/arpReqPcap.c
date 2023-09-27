#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>


//pcap raw paketi oluşturma

int main(int argc, char **argv){
	char *dev=NULL;//cihaz tanımlama
	pcap_t *fp;//pcap pointer
	char errbuf[PCAP_ERRBUF_SIZE];//error mekanizması, arayüzün açılmaması vs.
	u_char packet[42]; //42byte, 14byte ethernet çerçevesi(da,sa,type). geri kalanı arp çerçevesi
	//ethernet default 14byte(crc hariç),  arp 28byte çerçeve yapısı
	
	dev=pcap_lookupdev(errbuf); //cihaz aranıyor
	if (dev == NULL) {
        printf("Error finding device: %s\n", errbuffer);
        exit(EXIT_FAILURE);
    }
	printf("Aktif ethernet cihazi-> %s\n",dev);
	
	fp=pcap_open_live(dev, 100, 1, 1000, errbuf); //cihazdan paket yakalanmaya başladı (device, buffer size, başlangıç ve bitiş byte'ı)
	
	//ETHERNET ÇERÇEVE YAPISI
	
	//destination MAC ff:ff:ff:ff:ff:ff broadcast (request mesaj)
	packet[0]=0xff;
	packet[1]=0xff;
	packet[2]=0xff;
	packet[3]=0xff;
	packet[4]=0xff;
	packet[5]=0xff;
	
	//source MAC
	packet[6]=0xd4;
	packet[7]=0x3d;
	packet[8]=0x7e;
	packet[9]=0xea;
	packet[10]=0x6f;
	packet[11]=0xd5;
	
	//type
	packet[12]=0x08;
	packet[13]=0x06;
	
	//ARP BAŞLIK YAPISI
	
	//hardware type (0001 çünkü kendisini yani ethernet taşıyor)
	packet[14]=0x00;
	packet[15]=0x01;
	
	//protocol type (ip 0800)
	packet[16]=0x08;
	packet[17]=0x00;
	
	//hardware size
	packet[18]=0x06;

	//protocol size (ipv4 32bit)
	packet[19]=0x04;

	//operation code (req 0001)
	packet[20]=0x00;
	packet[21]=0x01;
	
	//source MAC
	packet[22]=0xd4;
	packet[23]=0x3d;
	packet[24]=0x7e;
	packet[25]=0xea;
	packet[26]=0x6f;
	packet[27]=0xd5;
	
	//source IP (10.9.27.225 olduğu varsayılırsa)
	packet[28]=0x0a;
	packet[29]=0x09;
	packet[30]=0x1b;
	packet[31]=0xe1;
	
	//destination MAC (bilmediğimiz için 00:00:00:00:00:00)
	packet[32]=0x00;
	packet[33]=0x00;
	packet[34]=0x00;
	packet[35]=0x00;
	packet[36]=0x00;
	packet[37]=0x00;
	
	//destination IP (10.9.27.100 olduğu varsayılırsa)
	packet[38]=0x0a;
	packet[39]=0x09;
	packet[40]=0x1b;
	packet[41]=0x64;
	
	
	//paketi doldurduk, yollamak kaldı
	if(pcap_sendpacket(fp, packet, 42) != 0){ //0 döndürmezse hata vardır
		fprintf(stderr, "\n Paketi gonderirken hata olustu: \n", pcap_geterr(fp));
		return;
	}
	
	return 0;
}