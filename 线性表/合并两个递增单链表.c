#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node,*LinkList;
LinkList CreateList(int n)//创建一个n个节点的单向链表
{
    LinkList head,p,q;
    int i;//循环计数器
    head=(LinkList)malloc(sizeof(Node));//给头指针分配节点
    head->next=NULL;//头节点固定不移动
    p=head;
    for(i=0;i<n;i++)
    {
        q=(Node*)malloc(sizeof(Node));
        scanf("%d",&q->data);
        q->next=NULL;
        p->next=q;
        p=q;//p是游标指针，q是用户输入的新节点；
    }
    return head;
}
void PrintList(LinkList L)
{
    LinkList p=L->next;//L就是链表头节点
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
LinkList Merge(LinkList L1,LinkList L2)//这是一个新链表
{
    LinkList head,p,q,r;
    p=L1->next;q=L2->next;r=head=(LinkList)malloc(sizeof(Node));//head不变，以便于找到链表头，r相当于是游标
    while(p&&q)// p!=NULL&&q!=NULL
    {
        if(p->data<=q->data)
        {
            r->next=p;p=p->next;r=r->next;
        }
        else
        {
            r->next=q;q=q->next;r=r->next;
        }
    }
    if(p)r->next=p;//把剩余多的节点补充进r
    if(q)r->next=q;
    return head;
}

int main()
{
    int n,m;
    LinkList L1,L2,L3;
    printf("请输入第一个链表的长度：");
    scanf("%d",&n);
    printf("请输入第一个链表的元素：");
    L1=CreateList(n);
    printf("第一个链表为：");
    PrintList(L1);
    printf("\n");
    
    printf("请输入第二个链表的长度：");
    scanf("%d",&m);
    printf("请输入第二个链表的元素：");
    L2=CreateList(m);
    printf("第二个链表为：");
    PrintList(L2);
    
     L3=Merge(L1,L2);
     printf("\n合并后的链表为: ");
     PrintList(L3);
     return 0; 
}