#include <stdio.h>

int repeat(int *array, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                sum++;
                break;
            }
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int result = repeat(array, n);
    printf("%d\n", result);
    return 0;
}