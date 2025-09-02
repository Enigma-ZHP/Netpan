#include"tcp_net_socket.hpp"

int tcp_init(const char* ip,int port)
{
    int sfd = socket(AF_INET,SOCK_STREAM,0);
    if(sfd == -1)
    {
        std::cout << "socket fail" << std::endl;

    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(ip);
    serveraddr.sin_port = htons(port);

    if(-1 == bind(sfd,(const sockaddr*)&serveraddr,sizeof(struct sockaddr)))
    {
        std::cout << "bind error" << std::endl;
        perror(" ");
        close(sfd);
    }
    if(-1 == listen(sfd,5))
    {
        std::cout << "listen fail" << std::endl;
        close(sfd);
    }
    return sfd;
}   

int tcp_accept(int sfd)
{
    struct sockaddr_in clientaddr;
    memset(&clientaddr,0,sizeof(clientaddr));
    socklen_t slen = sizeof(struct sockaddr);
    int newfd = accept(sfd,(sockaddr*)&clientaddr,&slen);
    if(-1 == newfd)
    {
        std::cout << "bind fail" << std::endl;
        close(sfd);
    }
    else
    {
        std::cout << "connect success " << inet_ntoa(clientaddr.sin_addr) << " " << ntohs(clientaddr.sin_port) << std::endl;
        return newfd;
    }

}

int tcp_connect(const char* ip,int port)
{
    int sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sfd)
    {
        std::cout << "client socket fail" << std::endl;
    }
    
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    inet_aton(ip,&serveraddr.sin_addr);
    serveraddr.sin_port = htons(port);

    if(-1 == connect(sfd,(const sockaddr*)&serveraddr,sizeof(serveraddr)))
    {
        std::cout << "connect fail" << std::endl;
        close(sfd);
    }
    return sfd;
    
}