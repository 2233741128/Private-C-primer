#include <stdio.h>
#define Pi 3.14
float S(float r) 
{
    float a;
    a = Pi * r * r;
    return a;
}
int main()
{
    float x, y;
    printf("请输入圆的半径r=");
    scanf("%f", &x);
    y = S(x);
    printf("圆的面积为：%f", y);
    return 0;
}