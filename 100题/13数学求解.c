//求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。
//例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
#include <stdio.h>
#include <math.h>
int main()
{
    int s=0,a,n,t;
    printf("请输入a的值以及相加次数:（s=a+aa+aaa+aaaa+aa...a）\n");
    scanf("%d %d",&a,&n);
    t=a;
    for(int i=1;i<=n;i++)
    {
        s+=t;
        a*=10;
        t+=a;
    }
    printf("s=%d",s);
}