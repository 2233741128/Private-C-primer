#include <stdio.h>
int main()
{
    int i,j,k,n;
    printf("请输入三角形的高\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)//i控制三角形的高
    {
        for(j=1;j<=n-i;j++)//j控制空格数：空格数为n-1
            printf(" ");
        for(k=1;k<=2*i-1;k++)//k是*数，为2*i-1
            printf("*");
        printf("\n");
    }
    return 0;

}