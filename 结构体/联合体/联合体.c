#include <stdio.h>
int main()
{
    union A
    {
        char a;
        int b;
        double c;
    };
    printf("联合体的大小为%u字节\n",sizeof(union A));//以最大成员的大小为联合体的大小。
    union A a1 ={'B'};
    a1.c=1.2;
    printf("%c %f",a1.a,a1.c);
    return 0;
}