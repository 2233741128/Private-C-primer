#include <stdio.h>
void huawen()//!无返回值的函数 空数据类型
{
    
    printf("-----------------\n");
    printf("请输入一个整数：\n");
    printf("-----------------\n");
}
int get1()//!有返回值的函数
{
    int n;
    printf("-----------------\n");
    printf("请输入一个整数：\n");
    printf("-----------------\n");
    scanf("%d",&n);
    return n;
    
}
/*
int main()//!无返回值
{
    int a,b;
    huawen();
    scanf("%d",&a);
    huawen();
    scanf("%d",&b);
    printf("result:%d",a+b);
    return 0;
}
*/
int main()//!有返回值
{
    printf("result:%d",get1()+get1());
    return 0;
}