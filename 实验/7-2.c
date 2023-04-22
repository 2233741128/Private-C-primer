#include <stdio.h>

void move(char a, char b) 
{
    printf("%c -> %c\n", a, b);
}

void hanoi(int n, char a, char b, char c) 
{
    if (n == 1) 
	{
        //如果只有一个圆盘，直接移动
        move(a, c);
    } 
	else 
	{
        //如果有多个圆盘，分三步进行
        hanoi(n - 1, a, c, b); //将n-1个圆盘从A移动到B
        move(a, c); //将最大的圆盘从A移动到C
        hanoi(n - 1, b, a, c); //将n-1个圆盘从B移动到C
    }
}
int main()
{
	int n;
	printf("请输入有几个盘子：\n");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
}