#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5//定义一个宏
int main() {

    int arr[SIZE];
    int i, j, temp;
    // 生成随机整数数组
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) 
        arr[i] = rand() % 100 + 1;
    // 打印原数组
    printf("原数组：\n");
    for (i = 0; i < SIZE; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    //! 冒泡排序
    for (i = 0; i < SIZE - 1; i++) //n-1次完成，共9次循环
    {
        for (j = 0; j < SIZE - 1 - i; j++) //一次循环，将大的值移动到最后面
        {
            if (arr[j] > arr[j + 1])  //检查前一个元素是否比后一个元素大
            { 
                temp = arr[j];   //将前一个大的赋值给temp
                arr[j] = arr[j + 1];//将后一个小的赋值给前一个
                arr[j + 1] = temp;//将temp赋值给后一个
                //升序，将前一个大的移动到后一个
            }
        }
    }    
    // 打印排序后的数组
    printf("排序后的数组：\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    #undef SIZE  //取消定义宏

    return 0;
}
