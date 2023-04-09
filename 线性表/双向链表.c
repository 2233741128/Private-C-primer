#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head;

struct Node* GetNewNode(int x)//生成一个结点 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x) 
{
    struct Node* newNode = GetNewNode(x);
    if(head == NULL)
	{
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print() 
{
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) 
	{
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL; // empty list
    InsertAtHead(2); Print();
    InsertAtHead(4); Print();
    InsertAtHead(6); Print();
}
/*这个例子定义了一个名为Node的结构体，其中包含了一个整型变量data和两个指针变量prev和next。然后定义了一个名为head的指针变量，它指向链表的头部。

接下来定义了一个名为GetNewNode()的函数，用于创建新的节点。该函数使用了动态内存分配函数malloc()来分配内存空间，并将新节点的数据域和指针域初始化。

然后定义了一个名为InsertAtHead()的函数，用于在链表头部插入新节点。该函数首先调用了GetNewNode()函数创建新节点，并判断链表是否为空。如果链表为空，则将新节点作为头部节点；否则将新节点插入到头部，并更新头部指针。

最后定义了一个名为Print()的函数，用于遍历并打印整个链表。

*/