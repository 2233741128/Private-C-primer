#include <stdio.h>
#include <stdlib.h>//内存管理函数

int main()
{
    void *p=malloc(4);//定义无类型指针变量p，通过malloc函数在堆中申请分配4字节的内存空间；malloc函数
    if (p!=NULL)
        *(int*)p=100;//如果申请成功，则把指针变量p更改为int类型并复制整数100；
    int *pi=(int*)malloc(4);//malloc函数返回类型为void,强制转换为int
    typedef struct Stu{
        char name[20];
        int age;
        float score;
    }STU;//将结构体命名为STU
    STU *pstu=(STU*)malloc(sizeof(STU));//定义指向结构体的指针，并强制转换malloc函数为结构体
    strcpy(pstu->name,"zhangsan");
    pstu->age=22;
    pstu->score=85.5f;
    printf("name:%s,age:%d,score:%.2f\n",pstu->name,pstu->age,pstu->score);


    int *p1 =(int *)malloc(sizeof(int));
    int *p2 =(int*)calloc(1,sizeof(int));//calloc(size_t,size_t size)第一个参数是申请个数，第二个是每一个的内存大小，适合数组
    printf("*p1=%d  *p2=%d",*p1,*p2);//calloc函数会将申请到的内存初始化为0；
    return 0;
}