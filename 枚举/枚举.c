#include <stdio.h>
int main()
{
    enum LPL{edg,rng,lng,blg};
    printf("edg=%d rng=%d lng=%d blg=%d\n",edg,rng,lng,blg);//成员是一个常量而不是变量，不能修改值。
    char arr[blg];//arr[3]
    int i=edg;//i=0
    i=blg+3;//i=3+3
    printf("%d",i);
    enum LPL l1;//定义枚举变量


}