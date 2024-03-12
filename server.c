//
// Created by Naku on 28/02/2024.
//

#include "server.h"

void bind_socket(SOCKET sock){
    struct sockaddr_in sin = { 0 };
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);

    if(bind(sock, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR){
        perror("bind()");
        exit(errno);
    }
}

void listen_to_conn_tcp(SOCKET sock){
    if(listen(sock, 5) == SOCKET_ERROR){
        perror("listen()");
        exit(errno);
    }
}

void listen_to_conn_udp(SOCKET sock, SOCKADDR_IN* from){
    char buffer[TAILLE_BUFFER];
    int fromSize = sizeof(*from);
    if((recvfrom(sock, buffer, strlen(buffer)-1, 0, (SOCKADDR *)from, (socklen_t *)&fromSize)) < 0){
        perror("udp()");
        exit(errno);
    }

    buffer[strlen(buffer)] = '\0';
    printf("Message recu : %s\n", buffer);
}

void app_tcp(){
    SOCKET sock = create_socket(SOCK_STREAM);
    bind_socket(sock);
    listen_to_conn_tcp(sock);

    SOCKET csock;
    struct sockaddr_in csin = { 0 };
    int sinsize = sizeof csin;

    csock = accept(sock, (struct sockaddr*)&csin, &sinsize);
    if(csock == INVALID_SOCKET){
        perror("accept()");
        exit(errno);
    }

    char buffer[TAILLE_BUFFER];
    printf("Bienvenue sur le serveur\n");

    while (1){
        int n = read_socket_tcp(csock, buffer, TAILLE_BUFFER);
        if(n == 0){
            break;
        }
//        write_socket_tcp(csock, buffer, n);
    }

    closesocket(csock);
}

void app_udp(){
    SOCKET sock = create_socket(SOCK_DGRAM);
    bind_socket(sock);

    struct sockaddr_in csin = { 0 };
    int sinsize = sizeof csin;



    char buffer[TAILLE_BUFFER];
    printf("Bienvenue sur le serveur\n");

    while (1) {
        listen_to_conn_udp(sock, &csin);
    }

    closesocket(sock);
}