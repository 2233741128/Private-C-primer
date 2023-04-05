//利用条件运算符?:的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
#include <stdio.h>
int main()
{
    int score;
    char t;
    printf("输入成绩：\n");
    scanf("%d",&score);
    t=(score>=90)?'A':((score>=60)?'B':'C');
    printf("%c",t);
}