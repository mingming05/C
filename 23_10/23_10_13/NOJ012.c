#include <stdio.h>
#include <math.h>

int digit(int n)
{
    int sum = 1;
    while (n / 10 != 0)
    {
        sum += 1;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    double sum = 0.0, a = 0.0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a = i + (i + 1) / pow(10, digit(i + 1));
        printf("%d.", i);
        int j = i + 1;
        while ((j) % 10 == 0)
        {
            j /= 10;
        }
        if (i != n)
        {
            printf("%d+", j);
        }
        else
        {
            printf("%d", j);
        }
        sum += a;
    }
    printf("=%.2lf", sum);
    return 0;
}
