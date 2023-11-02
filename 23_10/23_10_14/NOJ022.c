#include <stdio.h>
#include <math.h>

int main()
{
    long long unsigned int n;
    long long unsigned int c = 1;
    scanf("%llu", &n);
    if (n % 2 == 0)
    {
        for (long long unsigned int i = 0; i < (n / 2); i++)
        {
            c = (c * 20) % (long long unsigned int)(pow(10, 9) + 7);
        }
    }
    else
    {
        for (long long unsigned int i = 0; i < ((n - 1) / 2); i++)
        {
            c = (c * 20) % (long long unsigned int)(pow(10, 9) + 7);
        }
        c = (c * 5) % (long long unsigned int)(pow(10, 9) + 7);
    }
    printf("%llu", c);
    return 0;
}
