#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int k = n - i - j;
            if (k > j)
            {
                if (k * k == i * i + j * j)
                {
                    printf("%d\n", i * j * k);
                }
            }
        }
    }
    return 0;
}
