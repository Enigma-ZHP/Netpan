#include"cmd.hpp"
int main()
{
    while(true)
    {
        std::string cmd;
        std::string command;
        std::string vari;
        //int local = 0;
        std::cout << "enter your command: ";
        std::getline(std::cin,cmd);
        size_t local = cmd.find(' ');
   
        command = cmd.substr(0,local);
        vari = cmd.substr(local+1,cmd.size());
        //std::cout << "command=" << command << "|||||vari=" << vari << "||"<<std::endl;

        if(0 == command.compare("cd"))
        {
            cmd_cd(vari.c_str());
        }
        else if(0 == command.compare("pwd"))
        {
            cmd_pwd();
        }
        else if(0 == command.compare("ls"))
        {
            cmd_ls(vari.c_str());
        }


    }

}