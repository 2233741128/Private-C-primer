#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int i, count = 0;
    printf("请输入一句英文：");
    fgets(sentence, 1000, stdin);  // 从标准输入流中读取一行字符串
    // 统计单词数量
    for (i = 0; sentence[i] != '\0'; i++) 
	{
        if (!isspace(sentence[i]) && (isspace(sentence[i-1]) || i == 0)) 
		{
            count++;
        }
    }
    printf("该句话有 %d 个单词。\n", count);
    return 0;
}
