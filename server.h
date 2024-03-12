//
// Created by Naku on 28/02/2024.
//

#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include "util.h"

#define PORT 4000
#define TAILLE_BUFFER 1024

void bind_socket(SOCKET sock);
void listen_to_conn_tcp(SOCKET sock);

void listen_to_conn_udp(SOCKET sock, SOCKADDR_IN* from);

void app_tcp();
void app_udp();

#endif //SOCKET_SERVER_H
