#include <stdio.h>

int eulerTotient(int i)
{
    if (i == 1)
    {
        return 1;
    }
    int result = i, n = i;
    for (int j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            result = result * (j - 1) / j;
        }
        while (n % j == 0)
        {
            n /= j;
        }
    }
    if (n > 1)
    {
        result = result * (n - 1) / n;
    }
    return result;
}

int visible(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += eulerTotient(i);
    }
    if (n > 1)
    {
        sum = 2 * sum + 1;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", visible(n));
    return 0;
}