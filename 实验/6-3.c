#include <stdio.h>
double areaT(double a,double b,double h)
{
	double s;
	s=(a+b)*h/2;
	return s;
	
}
int main()
{
	double a,b,h;
	double s;
	printf("输入上底下底高：");
	scanf("%lf %lf %lf",&a,&b,&h);
	s=areaT(a,b,h);
	printf("%lf",s);
}