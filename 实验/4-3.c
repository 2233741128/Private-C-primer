#include <stdio.h>
int main()
{
   int num,y,count=0;
   printf("请输入一个正整数：\n");
   scanf("%d",&num);
   printf("逆序数字：");
   do
   {
    y=num%10;
    printf("%d",y);
    num/=10;
    count++;
   }while(num>0);
   printf("\n");
   printf("数字位数：%d",count);

}