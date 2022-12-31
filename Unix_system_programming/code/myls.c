#include<dirent.h>
#include<stdio.h>
#include "apue.h"
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        err_quit("Provide (only) one dir name\n");
    }
    else
    {
        DIR* dir;
        struct dirent* dir_entry;
        if((dir = opendir(argv[1])) == NULL)
            err_quit("Error opening directory\n");
        else
        {
            while((dir_entry = readdir(dir))!=NULL)
                printf("%s\n",dir_entry->d_name);
            closedir(dir);
        }
    }
    return 0;
}


