#include <stdio.h>

int harshardnum(int n)
{
    int ncopy = n, s = 0;
    while (ncopy)
    {
        s += ncopy % 10;
        ncopy /= 10;
    }
    if (s && n % s == 0)
    {
        return n / s;
    }
    return 0;
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    if (n == 1)
    {
        count = 1;
    }
    while (harshardnum(n)&&n!=1)
    {
        count++;
        n = harshardnum(n);
    }
    printf("%d", count);
    return 0;
}
