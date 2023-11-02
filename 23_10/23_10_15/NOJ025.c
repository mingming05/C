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

void formatting(int m, int n)
{
    int digitvalue = digit(n * m);
    int digitm = digit(m);
    int digitn = digit(n);
    int arrn[digitn];
    int ncopy = n;
    int digiteach[digitn]; // 等于n的每一位与m乘积的位数

    for (int i = 0; i < digitn; i++)
    {
        arrn[i] = ncopy % 10;
        ncopy /= 10;
        digiteach[i] = digit(arrn[i] * m);
    }

    for (int i = 0; i < digitvalue - digitm + 1; i++)
    {
        printf(" ");
    }
    printf("%d\nx", m);
    for (int i = 0; i < digitvalue - digitn; i++)
    {
        printf(" ");
    }
    printf("%d\n", n);
    for (int i = 0; i <= digitvalue; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < digitn-1; i++)
    {
        for (int j = 0; j < digitvalue - digiteach[i] + 1 - i; j++)
        {
            printf(" ");
        }
        printf("%d", arrn[i] * m);
        for (int k = 0; k < i; k++)
        {
            printf(" ");
        }
        printf("\n");
    }
    printf("+%d", arrn[digitn - 1] * m);
    for(int i = 0; i < digitn - 1; i++)
    {
        printf(" ");
    }
    printf("\n");
    for (int i = 0; i <= digitvalue; i++)
    {
        printf("-");
    }
    printf("\n ");
    printf("%d", m * n);
    return;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    formatting(m, n);
    return 0;
}
