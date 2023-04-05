//输出101-200以内的所有素数。
#include <stdio.h>
#include <math.h>
int main() {
    int is_prime;
    for (int i = 101; i <= 200; i++) 
    {
        is_prime = 1; // assume i is prime initially
        
        for (int j = 2; j <= sqrt(i); j++) 
        {
            if (i % j == 0) 
            {
                is_prime = 0; // i is not prime
                break;
            }
        }
        
        if (is_prime == 1) 
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
