#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof (struct stu)
struct stu
{
	int score;
	struct stu *next;
};
struct stu *head=NULL;//先让头指针为空
void addnode(int score)//插入元素score
{
	struct stu *newnode=(struct stu*)malloc(sizeof(struct stu));//为新插入的结点创建内存
	newnode->score=score;//新节点的数据域为输入的score
	newnode->next=NULL;//指针域为空
	if(head==NULL)
	{
		head=newnode;//如果头指针是空的，那就让新加入的节点变为头结点
	}
	else
	{
		struct stu *temp=head;
		while(temp->next!=NULL)//遍历，移动指针到链表末尾最后一个结点
		{
			temp=temp->next;
		}
		temp->next=newnode;//将原本链表末尾结点的指针域指向新增结点
	}
}
void del(int score)//删除指定的数据
{
	if(head==NULL)//如果链表为空，直接结束返回
	{
		return;
	}
	if(head->score==score)//如果要删除的是第一个结点
	{
		head=head->next;//头指针移动到下一个结点
	}
	else//如果不是删除第一个结点
	{
		struct stu *current=head;
		while(current->next!=NULL&&current->next->score!=score)//遍历链表找到要删除的结点位置
		{
			current=current->next;//，移动临时指针到要删除的结点位置的前一个
		}
		if(current->next!=NULL)//如果找到了要删除的节点，则将前一个节点的指针指向要删除节点的下一个节点
		{
			current->next=current->next->next;
		}
	}
}
void printnode()//打印链表
{
	struct stu *current=head;
	while(current!=NULL)
	{
		printf("%d->",current->score);
		current=current->next;//移动指针到下一个结点
	}
}
int main()
{
	addnode(61);
	addnode(85);
	addnode(98);
	addnode(100);
	printnode();
	printf("\n");

	del(85);
	printnode();
}



