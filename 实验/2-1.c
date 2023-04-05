#include <stdio.h>
#include <stdlib.h> //!引入rand函数来产生随机数
#include <time.h> //!引入time函数产生随机数种子
int main()

{
    srand(time(0));
    //!用time函数生成随机数种子来确保每次产生不同的随机数
    int target = rand()% 11 + 10;
    //!生成10到20之间的随机数，使用rand（）函数 区间为[0+10，10+10]
    int guess;
    printf("请开始猜数字游戏！\n");
        do //!开始循环
    {
        printf("请输入你猜的数字(10-20):");
        scanf("%d", &guess);
        if (guess < target) 
            printf("太小了，请继续尝试！");
        
        else if (guess > target) 
            printf("太大了，请继续尝试！");
        
    } while (guess != target);//!循环条件,若满足条件，继续循环，直到不满足为止。
    printf("恭喜，你猜对了！答案是%d。", target);
    return 0;
}
