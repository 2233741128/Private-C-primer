#include <stdio.h>
int main()
{
    struct Book
    {
        int isbn;//刊号
        char author[20];
        float price;
    };
    struct Book book1={1213123,"jiabaoyu",75.6f};
    struct Book *pBook = &book1;
    printf("刊号：%d，作者：%s,价格：%.2f\n",(*pBook).isbn,pBook->author,pBook->price);
    //*  指针运算符和箭头运算符；
    int *pisbn=&book1.isbn;  //*也可以直接定义一个指向结构体变量某个成员的指针
    printf("%d",*pisbn);
    return 0;
}