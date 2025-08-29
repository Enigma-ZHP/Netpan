#include"cmd.hpp"
int cmd_ls(const char* var)
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
    }else{
        std::cout << buf << std::endl;
        return 0;
    }
}

int cmd_mkdir(char* filename)
{
    if(0 == mkdir(filename,0774))
    {
        std::cout << "new dir create success" << std::endl;
        return 0;
    }else{
        std::cout << "mkdir error" << std::endl;
        return 1;
    }

}
int cmd_cd(const char* path)
{
    char buf[4096];
    if(0 == chdir(path))
    {
        getcwd(buf,4096);
        std::cout << "change dir success current dir is " << buf << std::endl;
        return 0;
    }
    else{
        std::cout << "cd fail" << std::endl;
        return 1;
    }
}

