#include <stdio.h>
#include <ctype.h>
enum Dir {UP,DOWN,LEFT,RIGHT};//定义枚举
void printDirect(enum Dir dir)
{
    switch (dir)//利用case后面只能加常量或者字符串常量
    {
        case UP:
            printf("方向是 UP\n");
            break;
        case DOWN:
            printf("方向是 DOWN\n");
            break;
        case LEFT:
            printf("方向是 LEFT\n");
            break;
        case RIGHT:
            printf("方向是 RIGHT\n");
            break;
        default:
            printf("方向错误\n");
            break;
    }
}
int main()
{
    enum Dir dir;//定义枚举变量
    char ch;//定义字符变量
    printf("请输入方向:");
    scanf("%c",&ch);
    ch=islower(ch)?toupper(ch):ch;//将小写转换为大写
    switch (ch)
    {
    case 'W':
        dir=UP;
        break;
    case 'S':
        dir=DOWN;
        break;
    case 'A':
        dir=LEFT;
        break;
    case 'D':
        dir=RIGHT;
        break;
    }
    printDirect(dir);//将枚举变量作为实参进行函数调用
    return 0;
}