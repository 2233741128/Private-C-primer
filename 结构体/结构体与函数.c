#include <stdio.h>

struct Rect {
    float len;
    float width;
    float area;
};
void cal(struct Rect *prect) {
    prect->area = prect->len * prect->width;
/*  rect.area=rect.len * rect.width;
    return rect;    */
}//等效 *prect.area
int main() 
{
    struct Rect rc;
    printf("请输入矩形的长和宽：\n");
    scanf("%f %f", &rc.len, &rc.width);
    cal(&rc);
    printf("面积为：%.2f\n", rc.area);
    return 0;
}
