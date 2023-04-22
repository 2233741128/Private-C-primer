#include <stdio.h>
#include <string.h>
int main()
{
	char d1[20]="hello";
	char d2[20]="Hello";
	char *s1="world";
	char *s2="World";
	strcat(d1,s1);//连接连个字符串
	printf("%s\n",d1);
	strcat(d2,s2);
	printf("%s\n",d2);
	int n=strlen(d1);//字符串长度
	printf("%d\n",n);
	char d[30];
	strcpy(d,s1);//字符串赋值函数
	printf("%s\n",d);
	
	
}