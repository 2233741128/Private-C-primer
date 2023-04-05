#include <stdio.h>

int main()
{
    //!确认有几个数
    int n;
    printf("请输入数组长度：\n"); 
    scanf("%d", &n);
    int a[n];
    printf("请输入%d个数：\n", n); 
    //!获得用户输入
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    //!逆序排列
    for(int i = 0; i < n / 2; i++)
    {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    //!输出数组
    printf("逆序存放后的数组为：\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
