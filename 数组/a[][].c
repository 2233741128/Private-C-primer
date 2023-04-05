#include <stdio.h>

int main() {
    // 定义一个二维数组，包含四个学生的语数英成绩
    int scores[4][3] = {//4是行指学生数量，
        {80, 75, 90},
        {85, 90, 82},
        {75, 80, 85},
        {90, 92, 88}
    };
    // 输出表格头部
    printf("  学生   语文  数学  英语\n");
    printf("-------  ----  ----  -----\n");
    // 使用循环遍历二维数组，并输出每个学生的成绩
    for (int i = 0; i < 4; i++) {
        printf("学生%d     %d    %d    %d\n", i + 1, scores[i][0], scores[i][1], scores[i][2]);
    }
    printf("\n");
    for (int j=0;j<4;j++ )
    {
        float total=0;
        for(int k=0;k<3;k++)
            total+=scores[j][k];
        printf("学生%d  总分：%.2f  平均分：%.2f\n",j+1,total,total/3);
    }
    return 0;
}
