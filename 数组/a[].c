#include <stdio.h>
int main()
{
    int a[5] ={1,2,3,4,5};
    printf("数组元素个数为：%llu\n",sizeof a/sizeof(int));
    printf("扩大十倍后：\n");
    for(int i=0;i<=4;++i)
        c(a[i]);
    printf("\n此时数组元素为：");
    for(int i=0;i<=4;++i)
        printf("\n%d",a[i]);
    printf("\n");
    printf("扩大100倍后：\n");
    array(a,5);
    printf("\n此时数组元素为:");
    for(int i=0;i<=4;++i)
        printf("\n%d",a[i]);
    return 0;
}
void c(int e)//不改变数组元素
{
    e*=10;
    printf("%d ",e);
}
void array(int arr[],int len)//改变数组元素
{
    for(int i=0;i<=len-1;i++)
        {arr[i]*=100;
        printf("%d ",arr[i]);
}}