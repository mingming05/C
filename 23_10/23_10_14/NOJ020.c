#include <stdio.h>

int main()
{
    int n;
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                for (int l = 0; l <= 9; l++)
                {
                    if (i + j + k + l == n)
                    {
                        count += 1;
                    }
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}
