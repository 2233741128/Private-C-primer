#include <stdio.h>
int main()
{
	int a[10];
	printf("输入十个数");
	for (int j=0;j<10;j++)
		scanf("%d",&a[j]);
	int count=0;
	for (int i=0;i<10;i++)
	{
		if(a[i]!=a[i+1])
		{
			count++;
		}
	}
	printf("%d",count);
}