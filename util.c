//
// Created by Naku on 28/02/2024.
//

#include "util.h"

SOCKET create_socket(int type)
{
    SOCKET sock = socket(AF_INET, type, 0);
    if(sock == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    return sock;
}

void init(void) {
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if (err < 0) {
        puts("WSAStartup failed !");
        exit(EXIT_FAILURE);
    }
#endif
}

void end(void) {
#ifdef WIN32
    WSACleanup();
#endif
}

int read_socket_tcp(SOCKET sock, char* buffer, int size){
    int n = recv(sock, buffer, size-1, 0);
    if(n < 0){
        perror("recv() tcp");
        exit(errno);
    }
    buffer[n] = '\0';
    printf("Message recu : %s\n", buffer);
    return n;
}

void write_socket_tcp(SOCKET sock, char* buffer, int size){
    if(send(sock, buffer, size, 0) < 0){
        perror("send() tcp");
        exit(errno);
    }
}