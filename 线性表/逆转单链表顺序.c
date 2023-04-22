#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int date;
	struct Node *next;
}Node,*LinkList;

LinkList creat(int n)//创建一个n个节点的单链表
{
	LinkList temp,new_node,head=(LinkList)malloc(sizeof(Node));
	head->next=NULL;head->date=0;
	temp=head;
	int i=0;
	while(i<n)
	{
		new_node=(Node*)malloc(sizeof(Node));
		scanf("%d",&new_node->date);
		new_node->next=NULL;
		temp->next=new_node;
		temp=new_node;
		i++;
	}
	return head;
}

void reverse(LinkList L)
{
    LinkList p,q;
    p=L->next;//p是头指针下一个节点
    L->next=NULL;
    while(p)
    {
		q=p->next;//移动q指针

		p->next=L->next;//头插法交换链表顺序
		L->next=p;

		p=q;//移动p指针

    }
    
}
/*我们定义了一个temp指针，
用于存储当前节点的下一个节点，
然后将当前节点指向前一个节点。最后将头节点指向temp即可。*/

void Print(LinkList L)
{
	LinkList p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->date);
		p=p->next;
	}
	printf("\n");
}


int main()
{
	int n;
	printf("请输入链表长度：\n");
	scanf("%d",&n);
	printf("请输入链表\n");
	LinkList L=creat(n);
	printf("链表为：\n");
	Print(L);
	reverse(L);
	printf("反转后：\n");
	Print(L);
	
}

