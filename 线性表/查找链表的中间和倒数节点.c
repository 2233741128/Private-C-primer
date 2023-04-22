//!带有头节点的单链表L，设计一个尽可能高效的算法求L中的中间节点
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int date;
	struct Node *next;
}Node;

Node* creat(int n)
{
	Node *head=(struct Node*)malloc(sizeof(Node));
	Node *temp,*new_node;
	head->date=0;
	head->next=NULL;
	temp=head;
	int i=0;
	while(i<n)
	{
		new_node=(Node*)malloc(sizeof(Node));
		scanf("%d",&new_node->date);
		new_node->next=NULL;
		temp->next=new_node;
		temp=temp->next;
		i++;
	}
	return head;
}

Node* Searchm(Node* L)
{
	Node *p,*q;
	p=L;//快指针，一次走两步，先到达链表末尾
	q=L;//慢指针，一次走一步，快指针到终点时它到达链表中间；
	while (p!=NULL&&p->next!=NULL)
	{
		p=p->next->next;
		q=q->next;
	}
	return q;
}
Node *SearchLast(Node *L,int n);

void Print(Node *L)
{
	Node *p=L->next;
	while(p)
	{
		printf("%d ",p->date);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	int n;
	printf("输入表长:\n");
	scanf("%d",&n);
	Node *L;
	printf("请输入链表:\n");
	L=creat(n);
	printf("链表为：\n");
	Print(L);
	Node* middle,*Last;
	middle=Searchm(L);
	printf("中间节点为：%d \n ",middle->date);
	Last=SearchLast(L,2);
	printf("倒数第2个节点为%d",Last->date);

}
Node *SearchLast(Node *L,int k)
{
	Node *p,*q;
	p=L->next;
	q=L->next;
	while(p->next)
	{
		if(--k<=0)//k减到0是慢指针开始走
			q=q->next;
		p=p->next;//快指针先走

	}
	if(k>0)
		return NULL;
	else
		return q;
}