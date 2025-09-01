#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int ret = 0;
    struct sockaddr_in address;
    char buf[1024];
//    bzero(&address,sizeof(address));
    memset(&address,0,sizeof(address));
    
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = INADDR_ANY;
    int opt = 1;
    int listenfd = socket(AF_INET,SOCK_STREAM,0);
    if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt)) == -1)
    {
        std::cout << "setsocketopt fail" << std::endl;
    }
    ret = bind(listenfd,(struct sockaddr*)&address,sizeof(struct sockaddr_in));
    if(ret == -1)
    {
        std::cout << "bind fail" << std::endl;
        close(listenfd);
    }
    ret = listen(listenfd,5);
    if(ret == -1)
    {
        std::cout << "listen fail" << std::endl;
        close(listenfd);
    }
    std::cout << "listen port" << std::endl;
    socklen_t slen = sizeof(address);
    int clientfd = accept(listenfd,(struct sockaddr*)&address,&slen);
    

    std::cout << "wait for client enter: ";
    int valread = read(clientfd,buf,sizeof(buf));
    std::cout << buf << " message accept." << std::endl;
   
    char information[10] = "you sb";
    int valsent = write(clientfd,information,sizeof(information));




    ret = close(clientfd);
    ret = close(listenfd);

    return 0;
}