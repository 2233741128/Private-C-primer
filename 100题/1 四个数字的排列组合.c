//!有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
#include<stdio.h>
int main()
{
    int i,j,k;
    printf("\n");
    for(i=1;i<8;i++) 
    { // 以下为三重循环
        for(j=1;j<8;j++) 
        {
            for (k=1;k<8;k++) 
            { // 确保i、j、k三位互不相同
                if (i!=k&&i!=j&&j!=k) 
                { 
                    printf("%d,%d,%d\n",i,j,k);
                }
            }
        }
    }
}