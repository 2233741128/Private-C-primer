#include <stdio.h>
#include <string.h>
// 统计单词数
int countWords(const char *str) 
{
    int count = 0;
    int inWord = 0;  // 是否在单词中
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            if (inWord) {  // 如果在单词中，单词数加1
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }
    if (inWord) {  // 处理最后一个单词
        count++;
    }
    return count;
}

int main() {
    char buf[1024];
    printf("请输入一行字符串：\n");
    fgets(buf, sizeof(buf), stdin);  // 使用 fgets() 函数读取一行字符串
    printf("你输入的是：\n");
    puts(buf);
    printf("你输入的字符个数为：%zu\n", strlen(buf));  // 使用 %zu 格式化字符串长度
    printf("你输入的单词个数为：%d\n", countWords(buf));  // 统计单词个数
    return 0;
}
