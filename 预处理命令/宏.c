#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 10
#define sqr(n) n*n
#define STR(s) #s  //#s表示将参数s转换为字符串类型
#define cnm(a,b) a##b   //将a和b连接在一起，并非字符串
#define m 1
int main()
{
    printf("MAX:%d\n",MAX(10,20));//20
    printf("n=%d\n",N);//10
    printf("%d\n",sqr(10));//10
    printf("%s\n",STR(1+9));//1+9
    printf("%d\n",cnm(10,20));//1020
    printf("%d\n",sqr(N));//100  宏也可以嵌套使用
    #ifdef m
    printf("A\n");
    #else
    printf("B\n");
    #endif

}