#include <stdio.h>
long int jiecheng(int m)
{
    long int s=1;
	printf("%d!+",m);
    while (m>1) 
	{
        s*=m;
        m--;
    }
    return s;
}
void quihe(int n)
{
	long int sum=0;
	int a;
	while (n>=1)
	{
		a=jiecheng(n);
		sum+=a;
		n--;
	}
	printf("=%ld",sum);
}
int main()
{
	int n;
    printf("请输入整数：\n");
	scanf("%d",&n);
    quihe(n);
    return 0;
}
