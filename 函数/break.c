#include <stdio.h>
int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j>=6)
                break;
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}
/*
只能在switch case语句或循环结构中使用
通常与if语句搭配
一旦被执行，则会强制中断流程，结束语句的执行
*/