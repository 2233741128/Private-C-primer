#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void InsertAtHead(int x) //头插法插入节点
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;//将头指针移动到最新一个节点上
}

void Insert(int x,int i)//在指定位置前插入节点;
{
    int j=1;
    struct Node* temp=head;
    while(j<i)
    {
        temp=temp->next;
        j++;
    }//移动游标到指定位置
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    temp->prev->next=newNode;//将指定位置前一个结点的后继指针指向新节点
    newNode->prev=temp->prev;//将新节点前驱指针指向原来位置前一个结点

    newNode->next=temp;//将新节点后继指针指向指定位置
    temp->prev=newNode;//将指定位置前驱指针指向新节点
}

void Delete(int i)//删除指定位置结点
{
    int j=1;
    struct Node* temp=head;
    while(j<i)
    {
        temp=temp->next;
        j++;
    }//移动游标到指定位置
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp); 
}

void Search(int i)//查找指定位置节点并取值
{
    int j=1;
    struct Node* temp=head;
    while(j<i)
    {
        temp=temp->next;
        j++;
    }
    printf("所查找元素值为：%d\n",temp->data);
}

void Print() //打印整个链表
{
    struct Node* temp = head;//头指针是最后一个插入的节点
    printf("Forward: ");
    while(temp->next != NULL) 
	{
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void headnode()//打印表长模块
{
    struct Node *temp=head;
    int count=0;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }
    temp->data=count;
    printf("表长：%d\n",temp->data);

}
int main() {
    //建立头节点
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=0;
    head->prev=head->next=NULL;
    InsertAtHead(10); Print();

    printf("头节点为：%d",head->next->data);//打印头节点0
    printf("\n");

    InsertAtHead(20); Print();
    InsertAtHead(30); Print();
    
    printf("此时头指针为：%d\n",head->data);
    InsertAtHead(40);
    InsertAtHead(50);Print();
    headnode();
    Search(3);

    Insert(100,3);
    Print();
    Delete(3);
    Print();

}
