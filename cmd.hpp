#ifndef CMD_HPP
#define CMD_HPP
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<iostream>
void error_show(int num);
int cmd_ls(char* var);
int cmd_mkdir(char* filename);
int cmd_chmod(char* filename,char* mode);
int cmd_cd(char* path);
int cmd_pwd();
int cmd_puts(char* filename);
int cmd_gets(char* filename);


#endif