#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,d,x,y;
    printf("请输入系数a,b,c的值：(空格分开)\n");
    scanf("%f %f %f",&a,&b,&c);
    if(a==0)
        printf("不是二次方程\n");
    else
    {
        d=b*b-4*a*c;
        if(d==0)
        {
            x=y=-b/(2*a);
            printf("方程有两个相同实根%.2f",x);
        }
        else if(d>0)
        {
            x=(-b+sqrt(d))/(2*a);
            y=(-b-sqrt(d))/(2*a);
            printf("方程有两个根：x1=%.2f x2=%.2f\n",x,y);
        }
        else
        {
            x=-b/(2*a);
            y=sqrt(-d)/(2*a);
            printf("有两个共轭复数根：x1=%.2f+%.2fi, x2=%.2f-%.2fi\n",x,y,x,y);
        }
    }
    return 0;
}