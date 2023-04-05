#include <stdio.h>
int main()
{
    for(int i=1;i<=100;++i)
    {
        if(i%2!=0)
            continue;
        printf("%d ",i);
    }
    return 0;
}
/*用法说明
1.只能在循环结构中使用
2.通常与if语句搭配
3.一旦被执行，则会跳过其后的语句，直接进入下一次循环
*/