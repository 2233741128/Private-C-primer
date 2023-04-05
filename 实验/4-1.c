#include <stdio.h>
int main()
{
    double  x;
    printf("请输入变量x的值");
    scanf("%lf",&x);
    if(x<1)
        printf("y=x=%lf",x);
    else if(x>=1&&x<10)
        printf("y=2x-1=%lf",2*x-1);
    else{
        printf("y=3x-11=%lf",3*x-11);
    }
    return 0;
}