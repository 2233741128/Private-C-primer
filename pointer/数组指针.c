#include <stdio.h>
int main()
{
	int a[4][3]={{1,2,3},
	{4,5,6},
	{7,8,9},
	{10,11,12}};
	int (*p)[3]=a;
	for (int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("a[%d][%d]=%d\n",i,j,*(*(p+i)+j));
		}
	}
}