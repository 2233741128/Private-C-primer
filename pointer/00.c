#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char *pst[3] = {"apple", "orange", "pear"};
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < strlen(pst[i]); j++) 
        {
            **pst = toupper(pst[j]);
        }
    }
    for (int f = 0; f < 3; f++) {
        printf("%s ", pst[f]);
    }
    return 0;
}
