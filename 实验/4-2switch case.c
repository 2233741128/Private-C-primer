#include <stdio.h>
int main()
{
    int score;
    printf("请输入百分制成绩：\n");
    scanf("%d",&score);
    printf("成绩为：");
    switch (score/10)
    {
    case 10:
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
    case 6:
    printf("C\n");
        break;
    default:
        printf("D\n");
        break;
    }
    return 0;
}