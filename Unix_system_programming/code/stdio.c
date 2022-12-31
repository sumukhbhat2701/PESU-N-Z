#include "apue.h"
int main()
{
    // buffered io
    char c;
    while((c = getc(stdin)) != EOF)
        if(putc(c, stdout) == EOF)
            err_sys("output erro\n");

    if(ferror(stdin))
        err_sys("input error\n");
    return 0;
}

