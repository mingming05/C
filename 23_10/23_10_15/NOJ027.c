#include <stdio.h>

int decompose(int n)
{
    int count = 1;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += j;
            if (sum == n)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", decompose(n));
    return 0;
}
