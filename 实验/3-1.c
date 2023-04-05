#include <stdio.h>
int main()
{
    int a;
    printf("请输入百分制成绩：");
    scanf("%d",&a);
    if(a>=85)
        printf("A");
    else if(a>=70&&a<=84)
        printf("B");
    else if(a>=60&&a<=69)
        printf("C");
    else if(a<60)
        printf("D");
    return 0;
}