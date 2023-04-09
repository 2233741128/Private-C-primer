#include <stdio.h>
#define Max 20
#define OK 1
#define ERROR 0

typedef struct//定义一个线性表结构体
{
	int date[Max];
	int lenth;
}SqList;

int GetElem(SqList L,int i,int *e)//第一个参数为线性表，第二个是需要更改的元素位置，第三个是需要更改的变量
{
	if(L.lenth==0||i<1||i>L.lenth)
		return ERROR;
	*e=L.date[i-1];
	return OK;
}
int ListInsert(SqList *L,int i,int e)//在L中第i个位置之前插入新元素e L长度+1
{
	int k;
	if(L->lenth==20)
		return ERROR;
	if(i<1||i>L->lenth+1)
		return ERROR;
	if (i<=L->lenth)//如果插入数据的位置不在表尾
	{
		for(k=L->lenth-1;k>=i-1;k--)//用k遍历插入位置后面的元素
			L->date[k+1]=L->date[k];//将要插入位置后的元素都向后移动一位
	}
	L->date[i-1]=e;
	L->lenth++;
	return OK;
}

int ListDelete(SqList *L,int i,int *e)//删除L的第i个数据元素，并用e返回其值，L长度-1
{
	int k;
	if(L->lenth==0)
		return ERROR;
	if(i<1||i>L->lenth)
		return ERROR;
	*e=L->date[i-1];
	if (i<L->lenth)
	{
		for (k=i;k<L->lenth;k++)
			L->date[k-1]=L->date[k];
	}
	L->lenth--;
	return OK;
}

int main()
{
	int b=1;
	SqList H={{1,2,3},
	3};
	GetElem(H,3,&b);
	printf("%d\n",b);
	ListInsert(&H,3,50);
	printf("%d\n",H.date[2]);
	//H={{1,2,50,3},4}
	int c;
	ListDelete(&H,1,&c);
	printf("被删除的元素是%d,此时线性表为：\n",c,H.date[0]);//date[3]={2,50,3}
	
	for(int m=0;m<3;m++)
		printf("%d ",H.date[m]);
	return 0;
}