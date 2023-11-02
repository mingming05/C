#include <stdio.h>

int gcd(int a, int b) // 感谢欧几里得先生，虽然我看不懂，但我大受震撼
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int visibleNuminMatrix(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (gcd(i, j) == 1&& (i != 0 || j != 0))
            {
                count++;
                printf("%d,%d ", i, j);
                printf("%d\n", count);
            }
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", visibleNuminMatrix(n));
    return 0;
}
