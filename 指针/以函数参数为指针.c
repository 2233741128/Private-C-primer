#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
void swap(int *pa,int *pb)
{
    int t=*pa;
    *pa=*pb;
    *pb=t;
}
void arry(int *arr,int len)
{
    for (int i=0;i<len;i++)
        printf("%d ",arr[i]);//也可以用*(arr+i)
}
int main()
{
    char str[3][MAX_LEN];//3个字符串，每个字符串的最大长度。
    printf("请输入三个字符串：\n");
    scanf("%s %s %s", str[0], str[1], str[2]);
    // 冒泡排序
    char temp[MAX_LEN];
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (strlen(str[i]) > strlen(str[j]))
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    printf("按升序排序后的字符串为：\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    }

    int m=10,n=20;
    swap(&m,&n);
    printf("\nm=%d,n=%d",m,n);
    return 0;
}
