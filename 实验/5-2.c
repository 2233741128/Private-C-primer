#include <stdio.h>
int main()
{
    int n=10,a[10];
    int t;
    //!获取输入
    printf("请输入十个数：\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    //!冒泡排序
    for(int j=0;j<n-1;j++)
        {
            for(int k=0;k<n-j-1;k++)
            {
                if(a[k]>a[k+1])
                {   t=a[k];
                    a[k]=a[k+1];
                    a[k+1]=t;
                }
            }
        }
    //!输出数组
    for (int m=0;m<n;m++)
        printf("%d ",a[m]);
}