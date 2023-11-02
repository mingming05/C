#include <stdio.h>

int main()
{
    long long unsigned n = 1, k;
    scanf("%d", &k);
    long long unsigned facmod = 1;
    while (facmod % k != 0)
    {
        n++;
        facmod = facmod * n % k;
        printf("%llu\n", facmod);
    }
    printf("%llu", n);

    return 0;
}
