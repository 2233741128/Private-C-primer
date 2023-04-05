/*一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？*/
#include <stdio.h>
#include <math.h>
int main() {
    int x;
    // 遍历可能的整数
    for (x = -100; x < 10000; x++) 
    {
        // 如果 x 小于 100，忽略此情况
        if (x < -99)
        {
            continue;
        }
        // 计算 x+100 的平方根
        int y = sqrt(x + 100);
        // 判断 y 是否是整数
        if (y * y == x + 100) 
        {
            // 计算 x+268 的平方根
            int z = sqrt(x + 268);
            // 判断 z 是否是整数
            if (z * z == x + 268) 
            {
                // 如果 x 同时满足条件，输出 x
                printf("这个数是:%d,%d+100=%d*%d    ", x,x,y,y);
                printf("%d+268=%d*%d\n",x,z,z);
            }
        }
    }
    return 0;
}
