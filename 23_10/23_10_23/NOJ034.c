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
    if (n == 1)
    {
        return count;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (gcd(i, j) == 1)
            {
                count++;
            }
        }
    }
    count = 2 * count + 1;
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", visibleNuminMatrix(n));
    return 0;
}