//!输入某年某月某日，判断这一天是这一年的第几天？
#include <stdio.h>
// 判断是否为闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// 计算该月有多少天
int getDaysOfMonth(int year, int month) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month-1];
}
// 计算该日期是该年的第几天
int getDayOfYear(int year, int month, int day) {
    int days = 0;
    for (int i = 1; i < month; i++) {
        days += getDaysOfMonth(year, i);
    }
    days += day;
    return days;
}
int main() {
    int year, month, day;
    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份：");
    scanf("%d", &month);
    printf("请输入日期：");
    scanf("%d", &day);
    int dayOfYear = getDayOfYear(year, month, day);
    printf("%d年%d月%d日是该年的第%d天。\n", year, month, day, dayOfYear);
    return 0;
}
