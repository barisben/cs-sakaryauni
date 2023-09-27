#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

char *dev = NULL;
pcap_t *fp;
char errbuffer[PCAP_ERRBUF_SIZE];
u_char packet[50];
int snapshot_length = 1024;

/* End the loop after this many packets are captured */
int total_packet_count = 10;

u_char *my_arguments = NULL;

struct bpf_program filter;
bpf_u_int32 subnet_mask, ip;
char filter_exp[26] = "icmp && dst ";
char dest_ip_str[30];
int src_ip[4];
int dest_ip[4];
double time_spent = 0.0;
clock_t begin = 0.0;
clock_t end = 0.0;

void packet_generator(int src_ip[4], int dest_ip[4]);
void filter_ip_address(char *device, char *dest_ip_str, char *filter_exp);
void my_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        printf("\nFormat: %s <address> -c <count>\n", argv[0]);
        return 0;
    }

    dev = pcap_lookupdev(errbuffer);

    if (dev == NULL)
    {
        printf("Error finding device: %s\n", errbuffer);
        exit(EXIT_FAILURE);
    }

    filter_ip_address(dev, dest_ip_str, filter_exp);

    // printf("filters:%s\n", filter_exp);

    if (pcap_lookupnet(dev, &ip, &subnet_mask, errbuffer) == -1)
    {
        printf("Could not get information for device: %s\n", dev);
        ip = 0;
        subnet_mask = 0;
    }

    //printf("Active ethernet device: %s\n", dev);

    fp = pcap_open_live(dev, 100, 0, 1000, errbuffer);
    if (fp == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuffer);
        return (2);
    }

    if (fp == NULL)
    {
        printf("Could not open %s - %s\n", dev, errbuffer);
        return 2;
    }
    if (pcap_compile(fp, &filter, filter_exp, 0, ip) == -1)
    {
        printf("Bad filter - %s\n", pcap_geterr(fp));
        return 2;
    }
    if (pcap_setfilter(fp, &filter) == -1)
    {
        printf("Error setting filter - %s\n", pcap_geterr(fp));
        return 2;
    }

    //destination ip parse
    {
        char *dest;
        dest = strtok(argv[1], ".");

        int i = 0;

        while (dest != NULL)
        {
            int tmp = atoi(dest);
            dest_ip[i] = tmp;
            //printf("destip:%d \n", dest_ip[i]);
            dest = strtok(NULL, ".");
            i++;
        }

        // source ip parse

        char *src;
        src = strtok(dest_ip_str, ".");

        int j = 0;

        while (src != NULL)
        {
            int tmp = atoi(src);
            src_ip[j] = tmp;
            // printf("srcip:%d \n", src_ip[j]);
            src = strtok(NULL, ".");
            j++;
        }
    }
  
    packet_generator(src_ip, dest_ip);
    int c = 1;
    int c_send = 0;
    int c_recieve = 0;
    int s = 0;
    printf("\n");
    while (s < atoi(argv[3]))
    {
        /* Send down the packet */

        time_spent = 0.0;
        if (pcap_sendpacket(fp, packet, 50 /* size */) != 0)
        {
            fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(fp));
            return 0;
        }

        c_send++;
        begin = clock();
       
        pcap_loop(fp, 1, my_packet_handler, my_arguments);   
            c_recieve++; 
       
    
        s++;
    }

    printf("\n<===PING RESULTS===>");
    printf("\n\n%d packet transmitted %d packet recieved ,%.2f%%packet loss", c_send, c_recieve, (double)((c_send - c_recieve) / c_send) * 100);
    pcap_close(fp);
    return 0;
}
void my_packet_handler(
    u_char *args,
    const struct pcap_pkthdr *header,
    const u_char *packet)
{



    if (packet[34] == 0x00 && packet[35] == 0x08) // capture only echo reply
    {

        end = clock();
        //printf("packet is received succesfully\n\n");

        /* First, lets make sure we have an IP packet */
        struct ether_header *eth_header;
        eth_header = (struct ether_header *)packet;
        if (ntohs(eth_header->ether_type) != ETHERTYPE_IP)
        {
            printf("Not an IP packet. Skipping...\n\n");
            return;
        }

        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

        printf("%d bytes from %u.%u.%u.%u ", header->caplen, packet[30], packet[31], packet[32], packet[33]);
        printf("ttl=%u time=%f milliseconds \n", packet[22], time_spent);
    }
}

void filter_ip_address(char *device, char *dest_ip_str, char *filter_exp)
{

    pcap_if_t *alldevs;
    int status = pcap_findalldevs(&alldevs, errbuffer);
    if (status != 0)
    {
        printf("%s\n", errbuffer);
        return;
    }

    for (pcap_if_t *d = alldevs; d != NULL; d = d->next)
    {
        if (strcmp(d->name, device) == 0)
        {
            //  printf("%s:", d->name);
            for (pcap_addr_t *a = d->addresses; a != NULL; a = a->next)
            {
                if (a->addr->sa_family == AF_INET)
                    //printf(" %s", inet_ntoa(((struct sockaddr_in*)a->addr)->sin_addr));
                    strcat(dest_ip_str, inet_ntoa(((struct sockaddr_in *)a->addr)->sin_addr));
            }
        }
    }
    strcat(filter_exp, dest_ip_str);
    //printf(":%s:\n\n",dest_ip_str);
}

void packet_generator(int src_ip[4], int dest_ip[4])
{

    //ICMP packet generate

    //Destination Mac-00:50:56:FC:18:27
    packet[0] = 0x00;
    packet[1] = 0x50;
    packet[2] = 0x56;
    packet[3] = 0xfc;
    packet[4] = 0x18;
    packet[5] = 0x27;

    //Source Mac-00:0C:29:cd:27:50
    packet[6] = 0x00;
    packet[7] = 0x0c;
    packet[8] = 0x29;
    packet[9] = 0xcd;
    packet[10] = 0x27;
    packet[11] = 0x50;

    //Tip

    packet[12] = 0x08;
    packet[13] = 0x00;

    //IP BAŞLIK YAPISI

    //versiyon+header lenght
    packet[14] = 0x45;

    //servis alanı

    packet[15] = 0x00;

    // total length

    packet[16] = 0x00;
    packet[17] = 0x24;

    //identification

    packet[18] = 0x10;
    packet[19] = 0xfd;

    //Fragmantaston

    packet[20] = 0x00;
    packet[21] = 0x00;

    //ttl değeri

    packet[22] = 0x40;

    //protocol bilgisi

    packet[23] = 0x01; //ICMPs

    //header cheksum

    packet[24] = 0x00;
    packet[25] = 0x00;

    //kaynak IP-192.168.1.37
    packet[26] = src_ip[0];
    packet[27] = src_ip[1];
    packet[28] = src_ip[2];
    packet[29] = src_ip[3];

    //hedef IP-192.168.1.34
    packet[30] = dest_ip[0];
    packet[31] = dest_ip[1];
    packet[32] = dest_ip[2];
    packet[33] = dest_ip[3];

    //ICMP REQUEST

    //tip alanı
    packet[34] = 0x08;

    //kod
    packet[35] = 0x08;

    //checksum

    packet[36] = 0x00;
    packet[37] = 0x00;

    //rest of header

    packet[38] = 0x11;
    packet[39] = 0x8d;
    packet[40] = 0x00;
    packet[41] = 0x1b;

    //zaman damgası
    packet[42] = 0xa6;
    packet[43] = 0x5d;
    packet[44] = 0x4d;
    packet[45] = 0x5e;
    packet[46] = 0x00;
    packet[47] = 0x00;
    packet[48] = 0x00;
    packet[49] = 0x00;
}