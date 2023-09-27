#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv){
	char *dev=NULL;
	pcap_t *fp;
	char errbuf[PCAP_ERRBUF_SIZE];
	
	u_char packet[50]; //14byte ethernet, 20byte ip header, 16byte icmp header
	
	dev=pcap_lookupdev(errbuf);
	if (dev == NULL) {
        printf("Error finding device: %s\n", errbuffer);
        exit(EXIT_FAILURE);
    }
	
	printf("Aktif arayuz-> %s\n", dev);
	fp=pcap_open_live(dev, 100, 1, 1000, errbuf);
	
	//ETHERNET ÇERÇEVESİ
	
	//destination MAC
	packet[0]=0x00;
	packet[1]=0x50;
	packet[2]=0x56;
	packet[3]=0xfc;
	packet[4]=0x18;
	packet[5]=0x27;
	
	//source MAC
	packet[6]=0xd4;
	packet[7]=0x3d;
	packet[8]=0x7e;
	packet[9]=0xea;
	packet[10]=0x6f;
	packet[11]=0xd5;
	
	//type | icmp olduğu için ip protokolü taşınması gerekiyor 0806
	packet[12]=0x08;
	packet[13]=0x06;
	
	
	//IP HEADER
	
	//version+header size (headerda version 4bit, hlen 4bit olduğu için yarım byte yazamayacağımızdan dolayı 2sini beraber 1 byte olacağı için alıyoruz)
	packet[14]=0x45; //4 version için (ipv4 old için), 5 header size için 4x5=20byte
	
	//service type 0 olarak verilsin
	packet[15]=0x00;
	
	//total size 2byte (50byte'ın 14byte'ı ethernet çerçevesi, yani total size 36byte olmalı. hex olarak 36 ise 0x24)
	packet[16]=0x00;
	packet[17]=0x24;
	
	//identification 2byte sallama değer
	packet[18]=0x10;
	packet[19]=0xac;
	
	//fregmantasyon paket parçalama bilgisi olmadığı varsayılarak 00 00
	packet[20]=0x00;
	packet[21]=0x00;
	
	//ttl 64 olacak hex olarak 0x40
	packet[22]=0x40;
	
	//protocol type (icmp 01)
	packet[23]=0x01;
	
	//checksum
	packet[24]=0x00;
	packet[25]=0x00;
	
	//destination IP (192.168.11.100 olduğu varsayılırsa)
	packet[26]=0xc0;
	packet[27]=0xa8;
	packet[28]=0x0b;
	packet[29]=0x64;
	
	//source IP (192.168.11.128 olduğu varsayılırsa)
	packet[30]=0xc0;
	packet[31]=0xa8;
	packet[32]=0x0b;
	packet[33]=0x80;
	
	//ICMP HEADER - REQUEST
	
	//type (req olduğu için 08)
	packet[34]=0x08;
	
	//code (req olduğu için submessage yok)
	packet[35]=0x00;
	
	//checksum
	packet[36]=0x00;
	packet[37]=0x00;
	
	//rest of header
	packet[38]=0x00;
	packet[39]=0x00;
	packet[40]=0x00;
	packet[41]=0x00;
	
	//time stamp (sallama dolduruldu)
	packet[42]=0xa6;
	packet[43]=0xb8;
	packet[44]=0xc4;
	packet[45]=0x12;
	packet[46]=0x11;
	packet[47]=0xc0;
	packet[48]=0x1d;
	packet[49]=0x09;
	
	
	//sonsuz kez paket gönderiliyor
	while(1){
		//paketi doldurduk, yollamak kaldı
		if(pcap_sendpacket(fp, packet, 50) != 0){ //0 döndürmezse hata vardır
			fprintf(stderr, "\n Paketi gonderirken hata olustu: \n", pcap_geterr(fp));
			return;
		}
	}
	
	
	return 0;
}