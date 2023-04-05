#include <stdio.h>
int main()
{
    int i,j,t;
    int min;
    //!用户输入数组
    int a[5];
    printf("请输入五个整数：");
    for (i=0;i<5;i++)
    {
        scanf("%d",&a[i]);    
    }
    //!选择排序，升序
    for(i=0;i<4;i++)//排序循环的次数
    {
        min=i;
        for(j=i+1;j<5;j++)//一次循环选择出最小值
        {
            if(a[j]<a[min])
                min=j; 
        }
        //选择出最小值后将最小值移动到前面
        t=a[min];
        a[min]=a[i];//互换a[min]和a[i]的值
        a[i]=t;
    }
    //!输出数组
    for(i=0;i<5;i++)
        printf("%d ",a[i]);
}