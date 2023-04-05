#include <stdio.h>    // 标准输入输出库
#include <time.h>     // 时间库
#include <unistd.h>   // 延时库

int main() {
    int scale = 50;   // 进度条总长度
    printf("%*s\n", scale/2 + 9, "执行开始");   // 输出进度条标题
    clock_t start = clock();   // 获取程序开始时间
    for (int i = 0; i <= scale; i++) 
    {
        float c = (float) i / scale * 100;   // 计算当前进度百分比
        int dur = (clock() - start) / CLOCKS_PER_SEC;   // 计算程序运行时间
        printf("\r%3.0f%%[%*s>%*s]%d.%02d秒", c, i, "", scale-i, "", dur/100, dur%100);   // 输出进度条
        fflush(stdout);   // 刷新输出缓冲区
        usleep(50000);   // 程序线程延时 50 毫秒
    }
    printf("\n%*s\n", scale/2 + 9, "执行结束");   // 输出进度条结尾
    return 0;// 程序正常退出
}
