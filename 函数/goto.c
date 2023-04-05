#include <stdio.h>
int main()
{
    int i=1;
aaa: //!标签
    printf("%d\n",i);
    i++;
    if(i<=10)
        goto aaa;
    return 0;
}
/*
一条goto对应一个标签
所对应的标签要在一个函数内
不能用c语言的关键字作为标签名
同一个函数内标签名不能抽工夫
goto语句通常和if语句搭配使用
*/