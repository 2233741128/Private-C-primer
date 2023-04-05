#include <stdio.h>
int main()
{
    char c;
    printf("输入一些字符：（回车结束）");
    while((c=getchar())!='n')
    {
        putchar(c);
    }
    return 0;

}