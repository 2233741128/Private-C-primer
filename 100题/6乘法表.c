//输出9*9口诀
#include <stdio.h>
int main()
{
    int i,j,result;
    for (i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            result=i*j;
            printf("%d*%d=%-3d",i,j,result); /*-3d表示左对齐，占3位*/
        }
    printf("\n"); /*每一行后换行*/
    }
}