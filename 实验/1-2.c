#include <stdio.h>
int main()
{
	int i,j,k;
	int n;
	printf("请输入菱形边长:");
	scanf("%d",&n);
	for(i=1;i<=n;i++) //i是行数 
	{
		for(j=1;j<=n-i;j++) //j是空格数 
			printf(" ");
		printf("*");
		for(k=1;k<=2*i-3;k++) //k是内部空格个数 
			printf(" ");
		if(i!=1)
			printf("*");
		printf("\n");
    }
    //下半 
    for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=n-i;j++)
			printf(" ");
		printf("*");
		for(k=1;k<=2*i-3;k++)
		printf(" ");
		if (i!=1)
			printf("*");
		printf("\n");
	} 
	return 0;	
}