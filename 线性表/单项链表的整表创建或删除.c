#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义链表结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建单向链表
struct ListNode *createList(int n) //n是链表数据域的个数
{
    struct ListNode *head = NULL;
    struct ListNode *cur = NULL;
    int i;
	srand(time(NULL));
    // 随机生成 n 个节点，并将它们插入链表
    for (i = 0; i < n; i++) {
        // 生成随机数
        int val = rand() % 100;
        // 创建新节点
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        // 将节点插入链表
        if (head == NULL) //设置头节点为第一个产生的随机数
		{
            head = node;
            cur = node;
        } 
		else 
		{
            cur->next = node;//将上一个结点的指针域指向新产生的结点
            cur = node;
        }
    }
    return head;
}

// 删除单向链表
void deleteList(struct ListNode *head) 
{
    struct ListNode *cur = head;
    while (cur != NULL) 
    {
        struct ListNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

//打印链表后删除链表
void printlist()
{
    struct ListNode *head=createList(10);
    struct ListNode *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->val);
        current=current->next;
    }
    printf("\n");
    deleteList(head);
    head->val=NULL;
    printf("%d",head->val);
}
// 测试代码
int main() 
{    
    printlist();
    return 0;
}
