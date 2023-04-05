#include <stdio.h>
int main()
{
	int i,j,k;//行数，空格数，*号数
	int n; //边长
	printf("请输入菱形边长:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)//上半行数为n
	{
		for(j=1;j<=n-i;j++)//空格数等于n-i
			printf(" ");
		for(k=1;k<=2*i-1;k++)
			printf("*");
		printf("\n");
	}
    for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=n-i;j++)
			printf(" ");
		for(k=1;k<=2*i-1;k++)
		printf("*");
		printf("\n");
	}
    return 0;
}