#include <stdio.h>

int main()
{
    int n, m, sum = 0;
    int array[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    scanf("%d", &m);
    for (int p = 0; p < n; p++)
    {
        if (m == array[p])
        {
            sum += 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}