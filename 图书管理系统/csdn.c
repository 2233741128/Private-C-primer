#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define LEN sizeof(book)

typedef struct book //确认结构体
{

	char id[8];
	char name[31];
	char author[27];
	char publish[31];
	double price;

}book;

void Menu1();//标题函数

void Menu2();//菜单函数

void WriteToFile();//书籍信息输入的函数

void ReadFromFile();//显示所有信息的函数

void QueryFile();//书籍的查询函数

void ModifyFile();//书籍的修改函数

void DeletFile();//删除数据的函数

int main()
{
	int select;
	
	do 
	{
		Menu1();
		Menu2();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			WriteToFile();
			break;

		case 2:
			ReadFromFile();
			break;

		case 3:
			QueryFile();
			break;

		case 4:
			ModifyFile();
			break;

		case 5:
			DeletFile();
			break;

		default:
			printf("退出程序！");
			exit(0);
			break;
		}
	}while ((select == 1 || select == 2)||(select == 3|| select == 4)||( select == 5));

	return 0;
}//利用switch函数进行菜单的选择

void Menu1()
{

	system("mode con cols=54 lines=30");
	system("color F2");
	printf("**********欢迎使用长沙理工大学图书管理系统***********\n");

}//标题函数1

void Menu2()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t1.录入图书\t\t\n");
	printf("\t\t2.显示图书\t\t\n");
	printf("\t\t3.查询图书\t\t\n");
	printf("\t\t4.修改图书\t\t\n");
	printf("\t\t5.删除图书\t\t\n");
	printf("\t\t0.退出\t\t\n");
	printf("\t\t输入你的操作：");

}//标题函数2

void WriteToFile()
{
	FILE *fp = NULL;
	book stu;
	char flag = 'y';
	fp = fopen("book1.dat", "ab+");//打开文件

	if (fp == NULL)
	{
		printf("文件打开失败！\n");
		exit(1);//1表示在有错的方式退出程序
	}

	while ((flag == 'y' || flag == 'Y'))
	{
		system("cls");
		Menu1();

		printf("请输入图书id：");
		scanf("%s", stu.id);

		printf("请输入书名：");
		scanf("%s", stu.name);

		printf("请输入书籍作者：");
		scanf("%s", &stu.author);

		printf("请输入出版社：");
		scanf("%s", &stu.publish);

		printf("请输入价格：");
		scanf("%lf", &stu.price);


		fwrite(&stu, LEN, 1, fp);
		fflush(stdin);

		printf("继续输入吗？继续请输入y或Y：");
		getchar();
		scanf("%c", &flag);
	}
	
	fclose(fp);//关闭文件
	return;
}//图书添加的函数

void ReadFromFile()
{
	system("cls");
	Menu1();
	FILE *fp = NULL;
	book stu;
	fp = fopen("book1.dat", "rb");

	if (fp == NULL)
	{
		printf("文件打开失败");
		exit(1);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("         id\t\t书名\t\t作者\n");

	fseek(fp, 0, SEEK_SET);

	while (!feof(fp))
	{
		if (fread(&stu, LEN, 1, fp))
		{
			printf("%10s\t%8s\t\t%5s\n", stu.id, stu.name, stu.author);
		}
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("pause");
	system("cls");
	fclose(fp);
	return;
}

void QueryFile()
{
	system("cls");
	Menu1();
	book stu;
	char x[8];
	int flag = 0;
	FILE *fp;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t请输入图书id:");
	scanf("%s", x);
	printf("  ID  书名    作者     出版社     价格\n");

	fp = fopen("book1.dat", "rb");

	if (fp == NULL)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("错误\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return;
	}
	
	fseek(fp, 0, SEEK_SET);
	while (fread(&stu, LEN, 1, fp))
	{

		if (strcmp(x, stu.id) == 0)
		{
			printf("%3s  %5s  %5s    %10s %5.2lf\n", stu.id, stu.name, stu.author, stu.publish, stu.price);
			flag = 1;
		}

		if (flag = 0)
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("没有图书信息");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fclose(fp);
	system("pause");
	system("cls");
	return;
}

void ModifyFile()
{
	system("cls");
	Menu1();
	book stu;
	FILE *fp;
	char x[8];

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("请输入图书id:");
	scanf("%s", x);

	fp = fopen("book1.dat", "rb+");

	if (fp == NULL)
	{
		printf("文件打开失败");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	while (fread(&stu, LEN, 1, fp))
	{

		if (strcmp(x, stu.id) == 0)
		{
			printf("请重新输入图书id:   ");
			scanf("%s", stu.id);

			printf("请重新输入书名:    ");
			scanf("%s", stu.name);

			printf("请重新输入书籍作者  : ");
			scanf("%s", &stu.author);

			printf("请重新输入图书出版社  : ");
			scanf("%s", &stu.publish);

			printf("请重新输入图书价格 :   ");
			scanf("%lf", &stu.price);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			fflush(stdin);
			fseek(fp, 0-LEN, SEEK_CUR);
			fwrite(&stu, LEN, 1, fp);
			fclose(fp);
		}

		if (feof(fp))
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("没有图书信息");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}

	}

	system("pause");
	system("cls");
	return;
}

void DeletFile()
{
	system("cls");
	Menu1();
	book s;
	FILE* fp;
	char a[10];
	fp = fopen("book1.dat", "rb+");

	if (fp == NULL)
	{
		printf("打开文件错误！！！\n");
		exit(1);
	}

	printf("\n请输入图书ID：");
	scanf("%s", a);
	printf("\n\t\t\t删除成功\n");

	fseek(fp, 0, SEEK_SET);
	FILE* fp1;
	fp1 = fopen("linshi.dat", "ab+");//读写新建一个临时文件

	while (fread(&s, LEN, 1, fp))//从原文件读一个结点
	{
		if (strcmp(a, s.id) != 0)//不是要删除的内容
		{
			fwrite(&s, LEN, 1, fp1);
		}
	}

	fclose(fp);
	fclose(fp1);
	remove("book1.dat");//删除原文件
	rename("linshi.dat", "book1.dat");//重命名为原文件

	fflush(stdin);
	system("pause");
	system("cls");
	return;
}
