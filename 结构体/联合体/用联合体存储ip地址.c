#include <stdio.h>
int main()
{
    union IP
    {
        unsigned char str[4];
        unsigned int digit;
        unsigned int f;
    };//只占用4字节,相比于字符数组所占用的内存更小，如果是内存数组则占据16字节。
    union IP ip;
    printf("输入ip地址:\n");
    scanf("%d.%d.%d.%d",&ip.str[0],&ip.str[1],&ip.str[2],&ip.str[3]);
    printf("数字ip地址：%u\n%u",ip.digit,ip.f);//利用联合体值会被覆盖的特点。

}