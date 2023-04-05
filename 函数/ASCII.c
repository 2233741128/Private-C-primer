#include <stdio.h>
int main()
{
    char a;
    printf("请输入一个字符：");
    scanf("%c",&a);
    printf("字符\'%c\'的ASCII编码为%d，字节长度%zd",a,a,sizeof(a));
}