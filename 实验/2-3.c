#include<stdio.h>
int main()
{
    int max=0,i,num;//!声明变量，max表示最大值，i作为循环次数，num为用户输入的数。
    for(i=1;i<=10;i++)
    {
        printf("请输入一个数：");
        scanf("%d",&num);
        if(num>max)
        {
             max=num;//!只要输入的数大于max，就将num值赋给max
        }
    }
    printf("最大值为：%d",max);
    return 0;
}