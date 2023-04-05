#include <stdio.h>
int main()
{
    float p,w,s,d,f;
    printf("请输入每吨每千米的基本运费，货物重量和运输距离：\n");
    scanf("%f %f %f",&p,&w,&s);
    if(s<250)
        d=1;
    else if(s>=250&&s<500)
        d=0.98;
    else if(s>=1000&&s<2000)
        d=0.92;
    else if(s>=2000&&s<3000)
        d=0.90;
    else if(s>=3000)
        d=0.85;
    f=p*w*s*d;
    printf("总运费为：%.2f",f);
    return 0;
}