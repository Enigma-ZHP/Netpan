#ifndef CMD_HPP
#define CMD_HPP
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<iostream>
#include<string>
void error_show(int num);
int cmd_ls(const char* var);
int cmd_mkdir(char* filename);
int cmd_chmod(char* filename,char* mode);
int cmd_cd(const char* path);
int cmd_pwd();
int cmd_puts(char* filename);
int cmd_gets(char* filename);

void cmd_handle(char* cmd);

#endif