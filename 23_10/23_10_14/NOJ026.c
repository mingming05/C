#include <stdio.h>

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

int isDecreasing(int n)
{
    int digitvalue = digit(n);
    int arr[digitvalue];
    int ncache = n;
    for (int i = 0; i < digitvalue; i++)
    {
        arr[i] = ncache % 10;
        ncache /= 10;
    }
    for (int i = 0; i < digitvalue - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (isDecreasing(n) == 0)
    {
        n -= 1;
    }
    printf("%d", n);
    return 0;
}
