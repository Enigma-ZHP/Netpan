#include"tcp_net_socket.hpp"

int main(int argc,char* argv[])
{
    if(argc < 3)
    {
        std::cout << "argc error" << std::endl;
        return 0;
    }
    int sfd = tcp_connect(argv[1],atoi(argv[2]));
    
    char buf[512] = {0};
    send(sfd,"hello",6,0);
    recv(sfd,buf,sizeof(buf),0);
    std::cout << buf << std::endl;
    close(sfd);
    return 0;
}