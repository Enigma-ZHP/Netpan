#ifndef __TCP_NET_SOCKET_HPP
#define __TCP_NET_SOCKET_HPP

#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<iostream>
#include<arpa/inet.h>
#include<string.h>


int tcp_init(const char* ip,int port);
int tcp_accept(int sfd);
int tcp_connect(const char* ip,int port);

#endif