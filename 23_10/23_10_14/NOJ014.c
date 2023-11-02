#include <stdio.h>

int main()
{
    long long unsigned int a, b, m, c = 1;
    scanf("%llu%llu%llu", &a, &b, &m);
    a %= m;
    b %= m;
    c = a * b % m;
    printf("%llu", c);
    return 0;
}
