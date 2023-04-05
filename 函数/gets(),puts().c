#include <stdio.h>
#include <string.h>
int main()
{
    char buf[1024];
    printf("请输入一行字符串：\n");
    gets(buf);
    printf("你输入的是：\n");
    puts(buf);
    printf("\n你输入的字符个数为：%llu\n",strlen(buf));
    return 0;
}