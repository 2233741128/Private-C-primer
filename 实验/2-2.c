#include <stdio.h>
int main()
{
    int year;
    for (year = 1900; year <= 2023; year++)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year%100==0 && year % 400 == 0))
        //!条件,&&是and，||是or，！是not
        {
            printf("%d 是闰年。\n", year);
        }
    }
    return 0;
}