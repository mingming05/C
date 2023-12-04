#include <stdio.h>

long long solve(int a, int b)
{
    if (a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    if (a % b == 0)
    {
        return a + a - b;
    }

    return a / b * (b + b) + solve(a % b, b);
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    printf("%lld", solve(x, n - x) + n);
}