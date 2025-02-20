#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_socket;
    struct sockaddr_in server;
    char buffer[1024] = {0};

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    send(client_socket, "Hello from client!", 18, 0);
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Server response: %s\n", buffer);

    close(client_socket);
    return 0;
}

