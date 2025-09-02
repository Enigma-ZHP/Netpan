#include"tcp_net_socket.hpp"
int main(int argc,char* argv[])
{
    if(argc < 3)
    {
        std::cout << "argc error" << std::endl;
    }
    else{
        std::cout << argv[1] <<" " << argv[2] << std::endl;
        int sfd = tcp_init(argv[1],atoi(argv[2]));
        int cfd = tcp_accept(sfd);
        char buf[512] = {0};
        if(-1 == recv(cfd,buf,sizeof(buf),0))
        {
            std::cout << "recv fail" << std::endl;
            close(sfd);
            close(cfd);
            return 0;
        }
        std::cout << buf << std::endl;
        char mesg[50] = "dont fucking send message!";
        if(-1 == send(cfd,mesg,sizeof(mesg),0))
        {
            std::cout << "send fail" << std::endl;
            close(cfd);
            close(sfd);
            return 0;
        }
        close(cfd);
        close(sfd);

    }
    return 0;
}