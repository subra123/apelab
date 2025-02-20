#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server, client;
    char buffer[1024];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    listen(server_socket, 1);
    
    printf("Server listening on port 8080...\n");
    
    socklen_t client_len = sizeof(client);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &client_len);
    printf("Connection established.\n");

    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);
    
    send(client_socket, "Hello from server!", 18, 0);

    close(client_socket);
    close(server_socket);
    return 0;
}

