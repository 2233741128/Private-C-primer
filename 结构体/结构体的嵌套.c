#include <stdio.h>
int main()

{
    struct Date
    {
        short year;
        short month;
        short day;
    };
    struct Person
    {
        char name[20];
        int age;
        float height;
        float weight;
        struct Date birthday;//嵌套使用。
    };
    struct Person zs = {"zhangpeng",19,1.78f,85.6f,{2004,9,28}};
    printf("birthday:%d-%d-%d",zs.birthday.year,zs.birthday.month,zs.birthday.day);
    //*需要使用两次成员访问运算符"."
    return 0;
}