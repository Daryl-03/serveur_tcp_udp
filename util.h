//
// Created by Naku on 28/02/2024.
//

#ifndef SOCKET_UTIL_H
#define SOCKET_UTIL_H

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#ifdef WIN32 /* si vous êtes sous Windows */

#include <winsock2.h>


void init(void);
void end(void);


#elif defined (linux) /* si vous êtes sous Linux */
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error not defined for this platform

#endif

SOCKET create_socket(int type);
int read_socket_tcp(SOCKET sock, char* buffer, int size);
void write_socket_tcp(SOCKET sock, char* buffer, int size);
typedef struct hostent Hostent;
#endif //SOCKET_UTIL_H
