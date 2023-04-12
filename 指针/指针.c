#include <stdio.h>
int main()
{
    //!指针变量
    int a=10,b=30,c;
    int *pi=&a,*pc=&c;//定义时*是标识符，指代指针&是获取变量的内存地址
    *pi=20;//a=20   使用时*是解引用，获取内存地址对应的变量
    pi=&b;//*pi=b=30
    *pc=10;//c=10
    ++*pi;//++b
    printf("*pi=%d,a=%d,c=%d",b,a,*pc);

    //!常量指针
    int d=100,f=200;
    const int *cpi=&d;//const修饰的是指针不是指针变量，
    //   *cpi=30;如果输入这行代码就会报错，指针被const修饰了无法赋值。
    printf("\n*cpi=%d",*cpi);
    cpi=&f;//指针变量不受限制仍然可以修改
    printf("\n*cpi=%u,f=%d",*cpi,f);

    //!指针常量
    int *const pcd=&d;//此时const修饰的是指针变量
    //pcd=&f;不可修改指针变量，指针变量现在是指针常量。
    *pcd=15;  //*指针不受限制，仍然可以修改
    printf("\n*pdc=%d,d=%d",*pcd,d);

    //!常量指针+指针常量
    int g=2,l=3;
    const int *const ph=&g;
    //*    *ph=100;
    //*    ph=&l;都无法使用，指针和指针常量都被限制

    const int a=10;
    int *pi=(int*)&a;//()强制将a转换成整数指针类型,再将a的内存地址赋值给pi
    *pi=20;
    printf("a=%d",a);//可以进行修改，只是限制了变量名a的使用
    
    //!指针算数运算（减法）
    int h[5]={1,2,3,4,5};
    int *p1=h;
    int *p2=&h[4];
    int c0=p2-p1;
    printf("\np2-p1=%d,p1+1=%d",c0,(p1+2));

}