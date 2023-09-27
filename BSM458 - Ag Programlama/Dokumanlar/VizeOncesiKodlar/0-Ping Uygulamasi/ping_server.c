#include <stdio.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <string.h>

//Function Prototypes
void swap(u_char *t1, u_char *t2); //yakalanan paketle oluşturulan paket arasındaki dönüşüm
void my_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);//paket yakalama
void filter_ip_address(char *device, char *dest_ip, char *filter_exp);//istemciden gelen ip adresi sunucudan gelenle aynı mı
//Global variables
char *device;
char error_buffer[PCAP_ERRBUF_SIZE];
pcap_t *handle;
/* Yakalanacak paket boyutu */
int snapshot_length = 1024;

/* Kaç paket yakalandığı */
int total_packet_count = 0;

u_char *my_arguments = NULL;

//soket programlama ile ilgili değişkenler
struct bpf_program filter;
char filter_exp[30] = "";
bpf_u_int32 subnet_mask, ip;
struct in_addr address;

char dest_ip[25];

int main(int argc, char **argv)
{
    device = pcap_lookupdev(error_buffer);
    if (device == NULL)
    {
        printf("%s\n", error_buffer);
        return 1;
    }

    strcpy(filter_exp, " icmp && dst "); //icmp ve destination kısmını birleştiriyoruz
    filter_ip_address(device, dest_ip, filter_exp);
	
	
    if (pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1)
    {
        printf("Could not get information for device: %s\n", device);
        ip = 0;
        subnet_mask = 0;
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer); //paket yakalamayı başlatıyoruz

    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open %s: %s\n", device, error_buffer);
        return (2);
    }
    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1)
    {
        printf("Bad filter - %s\n", pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &filter) == -1)
    {
        printf("Error setting filter - %s\n", pcap_geterr(handle));
        return 2;
    }

    pcap_loop(handle, total_packet_count, my_packet_handler, my_arguments);
    return 0;
}

void my_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{

    char error_buffer[PCAP_ERRBUF_SIZE];

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    unsigned char my_packet[50];
  
	//20byte ip header + 14byte icmp header
    if (packet[34] == 0x08 && packet[35] == 0x08) //ICMP echo request
    {
        //printf("yakaladım!!");
        for (int i = 0; i < header->caplen; i++)
        {
            /* code */
            my_packet[i] = packet[i];
        }

        //ip & mac adresses swap
		//kendi paketiyle yakalanan paketin bilgileri swap

        for (int i = 0; i < 4; i++)
        {
            swap(&my_packet[i + 0], &my_packet[i + 6]);   //mac adress swap "first 4 byte"
            swap(&my_packet[i + 26], &my_packet[i + 30]); //ip adresss swap
        }
        swap(&my_packet[4], &my_packet[10]);
        swap(&my_packet[5], &my_packet[11]); //mac adress swap "last 2 byte"

        //tip echo reply
        my_packet[34] = 0x00;

        if (pcap_sendpacket(handle, my_packet, 50) != 0)
        {
            fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(handle));
            return;
        }
        pcap_close(handle);

        /* First, lets make sure we have an IP packet */
        struct ether_header *eth_header;
        eth_header = (struct ether_header *)packet;
        if (ntohs(eth_header->ether_type) != ETHERTYPE_IP)
        {
            printf("Not an IP packet. Skipping...\n");
            return;
        }
        printf("it was captured a ICMP packet from %u.%u.%u.%u  !!\n", packet[26], packet[27], packet[28], packet[29]);
        printf("Total packet available: %d bytes\n\n", header->caplen);
        //printf("Expected packet size: %d bytes\n\n", header->len);
    }
}

void swap(u_char *t1, u_char *t2)
{
    u_char t;

    t = *t1;
    *t1 = *t2;
    *t2 = t;
}

void filter_ip_address(char *device, char *dest_ip, char *filter_exp)
{

    pcap_if_t *alldevs;
    int status = pcap_findalldevs(&alldevs, error_buffer);
    if (status != 0)
    {
        printf("%s\n", error_buffer);
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
                    strcat(dest_ip, inet_ntoa(((struct sockaddr_in *)a->addr)->sin_addr));
            }
        }
    }

    strcat(filter_exp, dest_ip);
    pcap_freealldevs(alldevs);
    printf("ip address : %s\n\n", dest_ip);
}