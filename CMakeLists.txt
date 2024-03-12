cmake_minimum_required(VERSION 3.28)
project(serveur_tcp_udp C)

set(CMAKE_C_STANDARD 99)

add_executable(serveur_tcp_udp main.c
    server.c
    server.h
    util.c
    util.h)
