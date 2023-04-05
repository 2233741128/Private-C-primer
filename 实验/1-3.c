#include <stdio.h>
int main()
{   int i,j,k;
    for(i=1;i<=4;i++)//!i是行数
    {   
        for(k=1;k<=i;k++)//!k是空格数
    {
        printf(" ");
    }
        for(j=1;j<=4;j++)//!j控制*的数量
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}