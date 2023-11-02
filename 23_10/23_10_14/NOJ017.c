#include <stdio.h>

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

int main()
{
    int sum, n;
    int count = 0;
    scanf("%d", &n);
    int digitvalue = digit(n);
    int arr[digitvalue];
    while (n > 0)
    {
        int ncache = n;
        for (int i = 1; i <= digitvalue; i++)
        {
            arr[digitvalue - i] = ncache % 10;
            ncache /= 10;
        }
        sum = 0;
        for (int i = 0; i < digitvalue; i++)
        {
            sum += arr[i];
        }
        n -= sum;
        count += 1;
    }
    printf("%d", count);
    return 0;
}
