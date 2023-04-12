#include <stdio.h>
#include <ctype.h>
int main()
{
    int a=10;
    int *pi=&a;
    *pi=20;
    int **pc=&pi;
    **pc=30;
    printf("%d ",a);

    char *pst[3]={"apple","orange","pear"};
    printf("%s\n",*(pst+1));//pst就是指第一个元素apple的内存地址,pst+1移动到orange
    printf("%c\n",*(*pst+3));
    char **ps=pst;
    for(int i=0;i<3;i++)
        printf("%s\n",*ps++);
}
    
