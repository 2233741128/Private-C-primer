#include <stdio.h>
int main()
{
    int a[5]={10,20,30,40,50};//数组名a表示第一个数组元素的内存地址，指向首个元素的指针
    int (*pArr)[5]=&a;//定义一个指向长度为5的int类型数组的数组指针，实质是二级指针
    for(int i=0;i<5;i++)
        {
            printf("%d ",*(*pArr+i));//   *pArr=a,和a一样表示数组中首个元素的内存地址。
    //* 指针移动法，括号内的*表示指向数组a的第一个元素，是一个内存地址，第二个才是单独解引用每个元素。
    //* 小括号内*pArr是对指针解引用，得到数组a，表示首个元素对应的内存地址，+i表示指针的移动，括号外的*得到内存地址对应的元素值。
            printf("%d ",(*pArr)[i]);
        }   //也可以使用下标法
    printf("\n\n");
    
    int arr[] = {99, 15, 100, 888, 252};
    int i, *p = arr, len = sizeof(arr) / sizeof(int);
    for(i = 0; i < len; i++){
        printf("%d ", *(p + i));
    }
    printf("\n");
    
    
    int b[2][3]={{10,20,30},
    {30,50,60}};
    int (*pq)[3]=b;//b表示一个指向长度为3的int类型数组的指针，不需要&
    //! *(*(pq+1)+2)表示第二行第三列的数据60
    for(int v=0;v<2;v++)
    {
        for (int j=0;j<3;j++)
            printf("%d ",*(*(pq+v)+j));//指针算数运算
        printf("\n");
    }
    printf("\n");
    for(int v=0;v<2;v++)
    {
        for (int j=0;j<3;j++)
            printf("%d ",pq[v][j]);//下标法
        printf("\n");
    }


}