#include <stdio.h>
#include <string.h>
struct Stu
{
    int num;//学号
    char *name;//姓名
};
int main()
{
    struct Stu stu1 ={1,"Tom"};
    char str1[20]="Tom";   
    stu1.name =str1;//* 让stu1的成员name指向字符数组str1

    struct Stu stu2 =stu1;//定义一个结构体变量并把stu1赋值给它
    char str2[20];
    stu2.name=str2;

    strcpy(stu2.name,"Jack");

    printf("stu1 Name:%s\n",stu1.name);
    printf("stu2 Name:%s",stu2.name);
    return 0;

}