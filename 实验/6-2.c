#include <stdio.h>
#include <string.h>

int main()
{
   char s1[100], s2[100], i, j;
   printf("输入第一个字符串: ");
   scanf("%s", s1);
   printf("输入第二个字符串: ");
   scanf("%s", s2);
   // 计算字符串 s1 长度
   for(i = 0; s1[i] != '\0'; ++i);
   // 将字符串 s2 复制到字符串 s1 的末尾
   for(j = 0; s2[j] != '\0'; ++j, ++i)
   {
      s1[i] = s2[j];
   }
   printf("连接后的字符串为: %s", s1);
   return 0;
}