#include <stdio.h>
#include <ctype.h>//包含islower函数
int main() {
  // 声明一个指针变量
  char *str;
  // 将指针变量指向一个字符串常量
  str = "Hello, World!";
  // 输出指针变量所指向的字符串常量
  printf("%s\n", str);

  //!字符数组与指针
  char s[]="apple";
  char *j=s;
  *s='A';
  *j='B';
  printf("%s",j);

  char st[] = {"Tel:017No.88#"};
  char *p = st; // 指向字符数组的指针
  while (*p != '\0') // 遍历字符数组
    {
        if (islower(*p)) // 如果当前字符是字母
            *p-=32; // 将其转换为大写字母,也可以使用 *p = toupper(*p)
        p++; // 移动到下一个字符
    }
    printf("\n%s\n", st); // 输出转换后的字符串
    return 0;
}





