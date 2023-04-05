//输入两个正整数m和n，求其最大公约数和最小公倍数。
#include <stdio.h>
int main()
{
    int n1,n2,t,t1;
    printf("输入两个整数：\n");
    scanf("%d %d",&n1,&n2);
    if(n1<n2)
    {    t=n1;
        n1=n2;
        n2=t;
    }
    int min;
    min=n1*n2;
    do
    {
        t1=n2;
        n2=n1%n2;
        n1=t1;
    }while(n2!=0);//用辗转相除法；
    min/=n1;//最小公倍数=输入的两个数之积除于它们的最大公约数，关键是求出最大公约数；
    printf("最大公约数：%d,最小公倍数：%d",n1,min);
    return 0;
}