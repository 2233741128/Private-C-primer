#include <stdio.h>
#include <time.h>
int asc(int a,int b)
{
    return a>b;
}
int desc(int a,int b)
{
    return a<b;
}
void bubble(int a[],int len,int (*pfunc)(int,int))//(*pfunc)(int,int)是一个函数指针，指向一个函数
{
    int i,j,t;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(pfunc(a[j],a[j+1]))//pfunc这里指的是一个未定函数，将指针指向一个函数后才有实际意义
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
int main()
{
    int w[10],b,choose;
    srand(time(NULL));
    for(int i=0;i<10;i++)
        w[i]=rand()%100+1;
    printf("升序==1，降序==2\n");
    scanf("%d",&choose);
    if(choose==1)
    {
        bubble(w,10,asc);//指针pfunc指向asc表示升序
    }
    else if(choose==2)
    {
        bubble(w,10,desc);
    }
    else
    {
        printf("选择数字错误！\n");    
    }
    for(int m=0;m<10;m++)
        printf("%d ",w[m]);
}