#include <stdio.h>
int main()
{
    struct Book
    {
        int isbn;//刊号
        char author[20];
        float price;
    };
    struct Book books[3]=//*将结构体变量定义为数组，即可定义一个结构体数组
    {
        {12345678,"贾宝玉",78.5f},
        {23242412,"刘慈欣",32.3f},
        {12321312,"冰心",21.6f}
    };
    for (int i=0;i<3;i++)
    {
        printf("ISBN:%d\n",books[i].isbn);//*下标法
        printf("AUTHOR:%s\n",(*(books+i)).author);//*指针移动法，利用数组名是首元素的内存地址。
        printf("PRICE:%.2f\n",(books+i)->price);//*也可以使用箭头运算符；
        printf("\n");
    }
    return 0;
}