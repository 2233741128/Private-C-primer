//将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5
#include <stdio.h>
int main()
{
    int num;
    printf("请输入一个整数:\n");
    scanf("%d",&num);
    printf("%d=",num);
    for(int i=2;i<=num;i++)
    {
        while (num%i==0)
        {
            printf("%d",i);
            num=num/i;
            if(num!=1)
            printf("*");                                  
        }
    }
}

