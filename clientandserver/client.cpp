#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main()
{
    int ret = 0;
    int clientfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in address;
    address.sin_port = htons(8080);
    address.sin_family = AF_INET;
    if(inet_pton(AF_INET,"127.0.0.1",&address.sin_addr) == -1)
    {
        std::cout << "inet_pton fail" << std::endl;
    }

    ret = connect(clientfd,(struct sockaddr*)&address,sizeof(address));
    
    char buf[100] = "hello";
    if(write(clientfd,buf,sizeof(buf)) < 0)
    {
        std::cout << "write error" <<std::endl;
    }
    char recvbuf[100];
    memset(recvbuf,0,sizeof(recvbuf));
    if(read(clientfd,recvbuf,sizeof(recvbuf)) < 0)
    {
        std::cout << "read error " << std::endl;
    }
    std::cout << recvbuf << std::endl;
    close(clientfd);
    return 0;
}