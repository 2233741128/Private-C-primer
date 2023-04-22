#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof (struct stu)
struct stu
{
	int score;
	struct stu *next;
};
struct stu *head=NULL;//先让头指针为空
void addnode(int score,int i)//插入元素score到第i个位置
{
	struct stu *newnode=(struct stu*)malloc(LEN);//为新插入的结点创建内存
	newnode->score=score;//新节点的数据域为输入的score
	newnode->next=NULL;//指针域为空
	if(head==NULL)
	{
		head=newnode;//如果头指针是空的，那就让新加入的节点变为头结点
	}
	else
	{
		struct stu *temp=head;
		int j=1;//从第一个结点位置开始遍历
		while(j<i-1)//将指针移动到插入点前的那个结点身上
		{
			temp=temp->next;
			j++;
		}
		newnode->next=temp->next;//右侧是下一个结点地址，左侧是节点的指针域
		temp->next=newnode;//将新节点的地址赋给指针域
	}
}
void del(int i)//删除指定位置的数据
{
	if(head==NULL)//如果链表为空，直接结束返回
	{
		return;
	}
	if(i==1)//如果要删除的是第一个结点
	{
		head=head->next;//头指针移动到下一个结点
	}
	else//如果不是删除第一个结点
	{
		struct stu *current=head;
		int j=1;
		while(current->next!=NULL&&j<i-1)//遍历链表找到要删除的结点位置
		{
			current=current->next;//移动临时指针到要删除的结点位置的前一个
			j++;
		}
		if(current->next!=NULL)//如果找到了要删除的节点，则将前一个节点的指针指向要删除节点的下一个节点
		{
			current->next=current->next->next;
		}
	}
}
void delete_date(int data) //删除指定的数据
{
    if (head == NULL) 
    {   
        return;
    }

    if (head->score == data) {   // 如果要删除的节点是头节点，则将头指针指向下一个节点
        head = head->next;
    } else 
	{

        struct stu* current = head;        
        while (current->next != NULL && current->next->score != data) 
		{  
            current = current->next;
        }
        if (current->next != NULL) {        
            current->next = current->next->next;
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
	addnode(20,1);
	addnode(30,2);
	addnode(50,3);
	addnode(40,3);
	addnode(60,5);
	addnode(70,5);
	printnode();
	printf("\n");

	
	del(3);
	delete_date(60);
	printnode();

}