#include"cmd.hpp"
int cmd_ls(char* var)
{
    DIR* dirp = NULL;
    struct dirent* direntp = NULL;

    dirp = opendir(".");
    if(dirp == NULL)
    {
        std::cout << "opendir end" << std::endl;
        return 1;
    }
    while(true)
    {
        direntp = readdir(dirp);
        if(direntp == NULL)
        {
            std::cout << "readdir fail" << std::endl;
            return 0;
        }

        std::cout << "ino = " << direntp->d_ino << " ";
        std::cout << "filename = " << direntp->d_name << std::endl;
    }
    closedir(dirp);
}

int cmd_pwd()
{
    char buf[4096];
    if(getcwd(buf,4096)==NULL)
    {
        std::cout << "pwd fail" << std::endl;
        return 1;
    }
    std::cout << buf << std::endl;
}