#include<stdio.h>
#include "apue.h"
#define BUFF_SIZE 4096

int main()
{
    int n;
    char buf[BUFF_SIZE];

    while((n = read(STDIN_FILENO/* file descriptor for stdin = 0 */, buf, BUFF_SIZE))>0)
        if(write(STDOUT_FILENO/*file descriptor for stdout = 1*/, buf, n) != n)
            err_sys("write error\n");
    if(n<0)
        err_sys("read error\n");


    return 0;
}
