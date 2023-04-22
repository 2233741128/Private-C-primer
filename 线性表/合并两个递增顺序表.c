#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

// 合并两个有序顺序表
void MergeList(SqList La, SqList Lb, SqList *Lc) 
{
    int i = 0, j = 0, k = 0;
    while (i < La.length && j < Lb.length) //i标记La j标记Lb
    {
        if (La.data[i] <= Lb.data[j]) 
        { // 如果La的当前元素小于等于Lb的当前元素
            Lc->data[k++] = La.data[i++]; // 将La的当前元素插入到Lc中
            //把小的元素放进去并将对应指针向后移动
        } 
        else 
        { // 否则
            Lc->data[k++] = Lb.data[j++]; // 将Lb的当前元素插入到Lc中
        }
    }
    while (i < La.length) 
    { // 如果La还有剩余元素
        Lc->data[k++] = La.data[i++]; // 将La剩余的元素插入到Lc中
    }
    while (j < Lb.length) { // 如果Lb还有剩余元素
        Lc->data[k++] = Lb.data[j++]; // 将Lb剩余的元素插入到Lc中
    }
    Lc->length = k; // 更新Lc的长度
}

int main() {
    SqList La = {{-3,1, 3, 5, 7}, 5};
    SqList Lb = {{2, 4, 6, 8}, 4};
    SqList Lc;
    MergeList(La, Lb, &Lc);
    for (int i = 0; i < Lc.length; i++) 
    {
        printf("%d ", Lc.data[i]);
    }
}
