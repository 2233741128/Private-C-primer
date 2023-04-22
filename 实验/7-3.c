#include <stdio.h>
#include <stdio.h>

void Spaces(int num) 
{
    int d = 1;
    while (num / d >= 10) 
	{
        d *= 10;
    }
    while (d > 0) 
	{
        printf("%d ", num / d);
        num %= d;
        d /= 10;
    }
    
}

int main()
{
	int num;
	printf("请输入一个整数：\n");
	scanf("%d",&num);
	Spaces(num);
}
