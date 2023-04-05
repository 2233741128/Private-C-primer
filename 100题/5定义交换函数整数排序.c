//输入三个整数x,y,z，请把这三个数由小到大输出。
#include <stdio.h>
void swap(int *pi,int *pj)
{
    int t;
    t=*pi;
    *pi=*pj;
    *pj=t;
}
int main()
{
    int x,y,z;
    printf("请输入三个数字：空格分开\n");
    scanf("%d %d %d",&x,&y,&z);
    if(x>y)
    {
        swap(&x,&y);
    }
    if(x>z)
    {
        swap(&x,&z);

    }
    if(y>z)
    {
        swap(&y,&z);
    }
    printf("%d %d %d",x,y,z);
    return 0;

}