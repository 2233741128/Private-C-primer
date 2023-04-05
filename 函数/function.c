#include <stdio.h>
//!函数声明 
int      max   (int     num1,  int     num2) 
//!数据类型  函数名(数据类型 参数1，数据类型 参数2)
{
   //!局部变量声明 
   int result;
   if (num1 > num2)
      result = num1;
   else
      result = num2;
   return result; 
}
int main ()
{
   //!局部变量定义
   int a;
   int b ;
   int ret;
   printf("请输入两个数（空格分开）：\n");
   scanf("%d %d",&a,&b);
   //! 调用函数来获取最大值
   ret = max(a, b);
   printf("Max value is : %d\n", ret);
   return 0;
}
//!函数返回两个数中较大的那个数 
 