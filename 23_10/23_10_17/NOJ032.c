#include <stdio.h>

int digit(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int isKeith(int n)
{
    int ncopy = n;
    int digitvalue = digit(n);
    int arr[100000];
    for (int i = 0; i < digitvalue; i++)
    {
        arr[digitvalue - i - 1] = ncopy % 10;
        ncopy /= 10;
    }
    for (int i = digitvalue; i < 100000; i++)
    {
        if (arr[i - 1] <= n)
        {
            for (int j = i - digitvalue; j < i; j++)
            {
                arr[i] += arr[j];
            }
        }
        else
        {
            return 0;
        }
        if (arr[i] == n)
        {
            return 1;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (isKeith(n))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
