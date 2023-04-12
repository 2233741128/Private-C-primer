#include <stdio.h>

#define MAX_SIZE 100  // 静态链表的最大容量

typedef struct 
{
    int data;
    int next;//相当于单链表中的next指针，存放date元素的后继在数组中的下标。称为游标
} Node;

Node list[MAX_SIZE];  // 静态链表的存储空间 相当于一个100个结点的链表
int head = 0;         // 头结点的位置

// 初始化静态链表
void initList() 
{
    for (int i = 0; i < MAX_SIZE; i++) 
	{
        list[i].data = 0;//每一个结点的数据为0
        list[i].next = i + 1;//指针域依次递增
    }
    list[MAX_SIZE - 1].next = -1;  // 最后一个结点的 next 指针设为 -1
}

// 在静态链表的末尾插入一个结点
void insert(int data) 
{
    int index = 1;//定义索引
    while (list[index].next != -1) //让指针移动到有数据的最后一个结点位置，有数据的最后一个位置的next为-1
	{
        index = list[index].next;
    }
    int new_index = list[head].next;  // 获取一个空闲结点的位置
    list[head].next = list[new_index].next;//让数组的第一个元素用来存放备用链表（未使用部分）第一个结点的下标，
    list[new_index].data = data;
    list[new_index].next = -1;
    list[index].next = new_index;//数组的最后一个元素用来存放第一个有数值的元素的下标，相当于头节点作用。
}

// 删除静态链表中第一个值为 data 的结点
void delete(int data) 
{
    int index = 1;
    while (list[index].next != -1) 
	{
        if (list[list[index].next].data == data) 
		{
            int delete_index = list[index].next;
            list[index].next = list[delete_index].next;
            list[delete_index].next = list[head].next;
            list[head].next = delete_index;
            return;
        }
        index = list[index].next;
    }
}

// 遍历静态链表
void print() 
{
    int index = 1;
    while (index != -1) 
	{
        printf("%d ", list[index].data);
        index = list[index].next;
    }
    printf("\n");
}

int main() {
    initList();
    insert(1);
    insert(2);
    insert(3);
	insert(4);
    print();
    delete(2);
    print();
    return 0;
}
