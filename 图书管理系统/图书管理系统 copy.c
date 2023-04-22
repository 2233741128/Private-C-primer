#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX_READER_NUM 20
#define MAX_STR_LEN 1000
//系统功能的实现
struct Date           /*日期结构*/
{
	int m_nYear;
	int m_nMonth;
	int m_nDay;
};
struct Reader         /*读者结构*/
{
	char num[20];     /*借书证号*/
	struct Date bro;  /*借出时间*/
	struct Date back; /*归还时间*/ 
};
struct Book		/*书本结构*/
{
	int m_iBook_Number;/*对应书本编号*/
	char m_strTitle[150];/*书名*/
	char m_strWroter[150];/*作者*/
	int m_nMoreNum; /*当前在架册数*/
	int m_nTotalHoldNum;/*馆藏册数*/
	char m_strComment[300];/*图书简介*/
	struct Reader reader[20];
};
struct Info    /*借书信息结构，双向链表*/
{
	struct Info *m_pParentPoint; /*指向当前节点的前驱结点，如果当前节点是头节点，则此指针为 NULL。*/
	struct Book *m_pBookInfo;	 /*对应书本的信息，指向当前节点存储的书本信息的结构体 Book。*/
	struct Info* m_pSun;		 /*指向当前节点的后继结点，如果当前节点是尾节点，则此指针为 NULL。*/

};
/*声明所需要用到的函数*/
struct Book* InputNode();/*图书上架*/
struct Info* Search(struct Info* bth, int x, int *k, int* flag); /*查找图书*/
struct Info* Insert_BookInfo(struct Info* bth);/*图书上架*/
struct Info* Delete_BookInfo(struct Info* bth);/*图书下架*/
void Output_BookInfo(struct Info* bth);/*打印输出书本信息*/
void Borrow_TheBook(struct Info* bth);/*图书借出*/
void TurnBack_TheBook(struct Info* bth);/*图书归还*/

/*系统选择菜单的实现*/
char Select_Menu()/*图书管理系统主菜单*/
{
	system("cls");
	printf("//********************************\\\n");
	printf("*                                  *\n");
	printf("*          图书馆管理系统           *\n");
	printf("*              主菜单              *\n");
	printf("*                                  *\n");
	printf("*          1.图书上架               *\n");
	printf("*          2.图书下架               *\n");
	printf("*          3.查找图书               *\n");
	printf("*          4.图书借出               *\n");
	printf("*          5.图书归还               *\n");
	printf("*          6.退出系统               *\n");
	printf("*                                  *\n");
	printf("*       请选择菜单项：（1-6）        *\n");
	printf("\\********************************//\n");
	return getchar(); 
}

/*图书上架功能的实现*/
struct Book* InputNode() //输入图书信息
{
    struct Book* p = NULL;
    p = (struct Book*)malloc(sizeof(struct Book)); //分配内存,作为数据域
    if (p != NULL)
    {
        system("cls"); //清屏
        printf("\n\t请输入书名：");
        fgets(p->m_strTitle, MAX_STR_LEN, stdin);
        printf("\n\t请输入作者：");
        fgets(p->m_strWroter, MAX_STR_LEN, stdin);
        printf("\n\t请输入当前在架册数：");
        scanf("%d", &p->m_nMoreNum);
        printf("\n\t请输入馆藏册数：");
        scanf("%d", &p->m_nTotalHoldNum);
        getchar(); //清除输入缓冲区中的换行符
        printf("\n\t请输入本书简介：");
        fgets(p->m_strComment, MAX_STR_LEN, stdin);
    }
    //以上为获得输入输出设备要求的信息
    for (int i = 0; i < MAX_READER_NUM; i++)
        p->reader[i].num[0] = '\0'; //初始化书本结构成员的相关读者指针内容为空
    return p;
}
struct Info* Insert_BookInfo(struct Info* bth)
{
    int flag, j, k, t;
    int x, y, z;
    struct Info* p = NULL, * q = NULL, * u = NULL, * s = NULL;
    struct Book* r = NULL, * l = NULL;
    system("cls");//清屏
    printf("\n\t请输入你想上架的书本号:");
    scanf("%d", &x);
    q = Search(bth, x, &k, &flag);//查找上架的书是否已经上架，返回已经找到的书的信息
    if (flag == 1)
    {
        /*查找成功，存在此书*/
        printf("\n\t当前存在这本书%d本，您想再增加一本《%s》书？（y/n）\n", q->m_pBookInfo->m_nTotalHoldNum, q->m_pBookInfo->m_strTitle);
        z = getchar();
        if (z == 'y' || z == 'Y')
        {
            /*确认上架另一本书*/
            printf("\n\t本馆一共有：%d本", q->m_pBookInfo->m_nTotalHoldNum);
            printf("\n\t并且有：%d本在图书馆内未借出。", q->m_pBookInfo->m_nMoreNum);
            q->m_pBookInfo->m_nTotalHoldNum++;
            q->m_pBookInfo->m_nMoreNum++;
            printf("\n\t上架后一共有%d本", q->m_pBookInfo->m_nTotalHoldNum);
            printf("\n\t上架后当前有：%d本在图书馆中", q->m_pBookInfo->m_nMoreNum);
        }
        return(bth);
    }
    r = InputNode(bth);/*成功插入书本信息，指针r存放刚刚插入的书*/
    if (bth == NULL)
    {
        /*指针bth为空时，表示当前链表为空，此时需要单独处理，即链表头内存分配*/
        bth = p = (struct Info*)malloc(sizeof(struct Info));
        r->m_iBook_Number = x;/*将书号存入书本信息结构体*/
        p->m_pParentPoint = NULL;
        p->m_pSun = NULL;
        p->m_pBookInfo = r;
        return(p);//p是头指针
    }
    else
    {
        /*说明此时已经有头指针，则在此开始处理新插入的结构体指针*/
        p = NULL;
        p = bth;//p是临时指针
        while (p->m_pSun != NULL)
        {
            p = p->m_pSun;//当后继结点不为空时，表示还未到链表尾部，用循环将指针移动到链表尾部
        }
        /*循环结束后，p指向的就是最后一个结点*/
        q = (struct Info*)malloc(sizeof(struct Info));//q是新建结点来存放新加入的书
        r->m_iBook_Number = x;//将书号存入书本信息结构体
	}
	return(bth);
}

void UpdateBook(struct Info* bth) {
    int bookID;
    struct Info* temp = bth;
    printf("Enter the Book ID to be updated: ");
    scanf("%d", &bookID);
    while (temp != NULL) {
        if (temp->m_pBookInfo->m_iBook_Number == bookID) {
            printf("\nEnter new Book ID: ");
            scanf("%d", &temp->m_pBookInfo->m_iBook_Number);
            printf("\nEnter new Book Title: ");
            scanf(" %[^\n]s", temp->m_pBookInfo->m_strTitle);
            printf("\nEnter new Author Name: ");
            scanf(" %[^\n]s", temp->m_pBookInfo->m_strWroter);
            printf("\nBook details updated successfully!");
            return;
        }
        temp = temp->m_pSun;
    }
    printf("\nBook not found.");
}

/*图书下架功能的实现*/
struct Info* Delete_BookInfo(struct Info* bth)
{
	int flag, j, k, t;
	int x, y;
	struct Info* u = NULL, * s = NULL, * p = NULL, * q = NULL;
	struct Book* bookinfo = NULL;
	struct Info* BookLeftPoint = NULL;//前驱
	struct Info* BookRightPoint = NULL;//后继
	system("cls");
	printf("\n\t请输入你想下架的书号：");
	scanf("%d", &x);
	q = Search(bth, x, &k, &flag);//查找指定的书是否存在
	if (flag == 0)
	{
		printf("\n\t这本书不存在!\n");
		return (bth);
	}
	else
	{
		if (q == NULL)
		{
			printf("未知错误！");
			return bth;
		}
		else
		{
			bookinfo = q->m_pBookInfo;
			printf("\n\t想下架的书本信息：");
			printf("\n\t书名：			%s", bookinfo->m_strTitle);
			printf("\n\t作者：			%s", bookinfo->m_strWroter);
			printf("\n\t当前在架册数：	%d", bookinfo->m_nMoreNum);
			printf("\n\t馆藏册数：		%d", bookinfo->m_nTotalHoldNum);
			printf("\n\t本书简介：%s\n", bookinfo->m_strComment);
			if (q->m_pParentPoint != NULL && q->m_pSun != NULL)
			{
				/*夹在链表中间的结点*/
				BookLeftPoint = q->m_pParentPoint;//要删除的结点的前驱指向赋给前驱结点的指针变量
				BookRightPoint = q->m_pSun;//要删除的结点的后继指向赋给后继结点的指针变量
				BookLeftPoint->m_pSun = BookRightPoint;//将后继结点指针指向的地址作为前驱节点中新后继域
				BookRightPoint->m_pParentPoint = BookLeftPoint;//将后继结点指向前驱域设定为要删除的结点的前驱节点

				q->m_pParentPoint = NULL;
				q->m_pSun = NULL;
				free(q->m_pBookInfo);//先将书本信息结构体的内存释放
				q->m_pBookInfo = NULL;//使指针指向安全地址
				free(q);//将要删除的借还书信息结构体指针使用的内存空间释放
				q = NULL;//要习惯将动态分配的内存在使用后动态释放，并将指针域指向空
				return bth;//返回首结点
			}
			else if(q->m_pParentPoint=NULL)
			{//首结点的前驱为空，这里处理首届点删除操作
				if (q->m_pSun == NULL)
				{
					free(q->m_pBookInfo);
					q->m_pBookInfo = NULL;
					free(q);
					q = NULL;
					return q;
				}
				bth = q->m_pSun;
				bth->m_pParentPoint = NULL;
				//要删除的结点的后继指向赋给后继结点的指针变量
				BookRightPoint = q;
				BookRightPoint->m_pParentPoint = NULL;//将链表中指向首结点的后继指针的前驱指针域置为空，表明是新首节点
				BookRightPoint->m_pSun = NULL;//将链表中指向首结点的后继指针的前驱指针域置为空，表明是新首节点
				free(BookRightPoint->m_pBookInfo);//释放书本信息结构体的内存
				BookRightPoint=NULL;
				return bth;//返回首结点
			}
			else if (q->m_pSun == NULL)
			{
				//尾结点的后继结点为空，这里处理尾结点的删除操作
				BookLeftPoint = q->m_pParentPoint;
				BookLeftPoint->m_pSun = NULL;
				q->m_pParentPoint = NULL;
				free(q->m_pBookInfo);
				q->m_pBookInfo = NULL;
				free(q);
				q = NULL;
				return bth;
			}
		}
	}
}


//查找图书
struct Info* Search(struct Info* bth, int x, int* k, int* flag)
{
	struct Info* p = bth;
	*flag = 0;
	while (p != NULL)
	{
		if (p->m_pBookInfo->m_iBook_Number == x)
		{
			*flag = 1;
			return p;
		}
		if (p->m_pSun != NULL)
		{
			p = p->m_pSun;
		}
		else
		{
			break;
		}
	}
	return NULL;
}

void Output_BookInfo(struct Info* bth) 
{
    int bookNumber, flag = 0;
	system("cls");
    printf("请输入书本编号：");
    scanf("%d", &bookNumber);
	
	struct Info* book = Search(bth, bookNumber, NULL, &flag);
	
    if (flag) 
	{
        printf("书本编号：%d\n", book->m_pBookInfo->m_iBook_Number);
        printf("书名：%s\n", book->m_pBookInfo->m_strTitle);
        printf("作者：%s\n", book->m_pBookInfo->m_strWroter);
        printf("当前在架册数：%d\n", book->m_pBookInfo->m_nMoreNum);
        printf("馆藏册数：%d\n", book->m_pBookInfo->m_nTotalHoldNum);
        printf("图书简介：%s\n", book->m_pBookInfo->m_strComment);
        flag = 1;
    }

    if (!flag) 
	{
        printf("未找到编号为%d的书本信息！\n", bookNumber);
    }
}

//首先要输入要查找的书本编号，然后通过遍历双向链表来查找是否有该编号的书本信息，如果找到就打印出来，否则输出未找到的提示信息。


//借书功能的实现
void Borrow_TheBook(struct Info* bth)
{
    struct Info* q = NULL;
    struct Book* p = NULL;
    int i, k, x, flag, t;
    system("cls");
    printf("\n\t请输入你想借的书号：");
    scanf("%d", &x);
    q = Search(bth, x, &k, &flag);
    if (flag == 1)
    {
        p = q->m_pBookInfo;
        printf("\n\t借出这本书？（y/n）");
        printf("\n\t书名			%s", p->m_strTitle);
        printf("\n\t作者			%s", p->m_strWroter);
        printf("\n\t当前在架册数： 		%d", p->m_nMoreNum);
        printf("\n\t馆藏册数：		%d", p->m_nTotalHoldNum);
        printf("\n\t本书简介：%s\n", p->m_strComment);
        t = getchar();
        if (t == 'y' || t == 'Y')
        {
            if (p->m_nMoreNum == 0)
            {
                printf("\n\t对不起，本书已经全部借出");
            }
            else
            {
                system("cls");
                for (i = 0; i < 20; i++)
                {
                    if ((p->reader[i]).num[0] == '\0')
                        break;
                }
                if (i < 20)
                {
                    printf("\n\t请输入借书证号：");
                    scanf("%s", p->reader[i].num);
                    printf("\n\t请输入借出的日期：");
                    printf("\n\t年");
                    scanf("%d", &(p->reader[i].bro.m_nYear));
                    printf("\n\t月");
                    scanf("%d", &(p->reader[i].bro.m_nMonth));
                    printf("\n\t日");
                    scanf("%d", &(p->reader[i].bro.m_nDay));
                    p->m_nMoreNum--;
                    printf("\n\t成功借到书本");
                    return;
                }
                else
                {
                    printf("\n\t借书人数已满");
                }
            }
        }
    }
    else
    {
        printf("\n\t这本书不存在！");
    }
}


//还书功能的实现
void TurnBack_TheBook(struct Info* bth)
{
	struct Info* q = NULL;
	struct Book* p = NULL;
	int i, k, x, flag, t, j;
	int year, month, day, d;
	float pay;
	char temp[20];
	system("cls");
	printf("\n\t请输入归还的书号");
	scanf("%d", &x);
	q = Search(bth, x, &k, &flag);
	if (flag == 1)
	{
		p = q->m_pBookInfo;
		printf("\n\t你想归还这本书？（y/n）");
		printf("\n\t书名			%s", p->m_strTitle);
		printf("\n\t作者			%s", p->m_strWroter);
		printf("\n\t当前在架册数： 		%d", p->m_strTitle);
		printf("\n\t馆藏册数：		%d", p->m_nTotalHoldNum);
		printf("\n\t本书简介：%s\n", p->m_strComment);
		t = getchar();
		if (t == 'y' || t == 'Y')
		{
			if ((p->m_nMoreNum) >= (p->m_nTotalHoldNum))
				printf("\n\t想再上架一本书吗？\n");
			else
			{
				system("cls");
				printf("\n\t请输入借书证号：");
				scanf("%s", temp);
				j = 0;
				for (i = 0; i < 20; i++)
				{
					if (!(strcmp(temp, (p->reader[i]).num)))
					{
						j = 1;
						break;
					}
				}
				if (j == 0)
				{
					printf("\n\t你不能借这本书。");
					return;
				}
				printf("\n\t今天是：");
				printf("\n\t年：");
				scanf("%d", &year);
				printf("\n\t月：");
				scanf("%d", &month);
				printf("\t日：");
				scanf("%d", &day);
				d = 0;
				if (year < (p->reader[i]).back.m_nYear)
					d = 1;
				if (year <= (p->reader[i]).back.m_nYear && month < (p->reader[i]).back.m_nMonth)
					d = 1;
				if (year <= (p->reader[i]).back.m_nYear && month < (p->reader[i]).back.m_nMonth && day < (p->reader[i]).back.m_nDay)
					d = 1;
				if (d == 0)
				{
					system("cls");
					printf("超过截至日期罚款5元！");

				}
				(p->reader[i]).num[0] = '\0';
				p->m_nMoreNum++;
				printf("成功归还");
			}
		}
	}
	else
		printf("你不能归还不存在的一本书！");
}


//主函数功能的实现
void main()
{
	char c, t;
	int flag, p = 1;
	struct Info* bth = NULL;
	while (1)
	{
		c = Select_Menu();
		printf("您选择了：%c", c);
		getchar();
		switch(c)
		{
			case '1':
				bth = Insert_BookInfo(bth);
				break;
			case '2':
				bth = Delete_BookInfo(bth);
				break;
			case '3':
				Output_BookInfo(bth);
				break;
			case '4':
				Borrow_TheBook(bth);
				break;
			case '5':
				TurnBack_TheBook(bth);
				break;
			case '6':
			case '0':
				system("cls");
				printf("\n\t你想退出系统？（y/n）");
				t = getchar();
				if (t == 'y' || t == 'Y')
					exit(0);
				break;
		}
		printf("\n\t按任意键返回主菜单");
		getchar();

	}
}