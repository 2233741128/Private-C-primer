#include <stdio.h>
#include <string.h>
int main()
{
    //!定义一个结构体Person
    struct Person
    {
        char name[20];
        int age;
        float height;
        float weight;
    };
    struct Person p1 = {"Tom",20,1.78f,63.5f};//定义结构体变量p1
    struct Person p2 =p1;//定义并赋值p2
    strcpy(p1.name,"David");//给p1的name重新赋值
    printf("%s\n",p1.name);
    printf("%s\n",p2.name);
    struct Person p5={.name="Rose",.height=1.65f};//也可以选择赋值
    printf("%s  %.2f  %d\n",p5.name,p5.height,p5.age);
    p5.age =20;//也可以这样赋值前提是已经定义过了。
    p5.weight=48;
    printf("%d  %.2f\n",p5.age,p5.weight);


    printf("结构体大小为%u",sizeof(struct Person));
    //*大小为各个成员大小的累加，有时需要考虑内存对齐的情况，以4字节为单位储存

    
    return 0;

}