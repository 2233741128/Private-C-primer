#include <stdio.h>
#include "a.h"
#include "head.h"
int main()
{
    printf("1+5=%d\n",add(1,5));
    struct STU stu1;
    stu1.num=7;
    printf("%d",stu1.num);
}