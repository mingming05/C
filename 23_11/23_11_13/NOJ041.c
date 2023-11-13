#include <stdio.h>

int ifSymmetricalinKSys(int n, int k)
{
    int ncopy = n;
    int i;
    int arr[1000] = {0};
    for (i = 0; ncopy; i++)
    {
        arr[i] = ncopy % k;
        ncopy /= k;
    }
    for (int j = 0; j <= i / 2; j++)
    {
        if (arr[j] != arr[i - j - 1])
        {
            return 0;
        }
    }
    return 1;
}

int ifSymmetrical(int n, int k)
{
    if (ifSymmetricalinKSys(n, k) == 0)
    {
        return 0;
    }
    if (ifSymmetricalinKSys(n, 10) == 0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (ifSymmetrical(i, k))
        {
            sum += i;
        }
    }
    printf("%d", sum);
    return 0;
}