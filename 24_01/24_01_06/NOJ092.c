#include <stdio.h>

double countpai(int n)
{
    double pai = 3.0;
    int minus = 1;
    for (int i = 2; i <= n; i++)
    {
        minus = 1;
        if (i % 2)
        {
            minus = -1;
        }
        pai += minus * 4.0 / (2 * i * (2 * i - 1) * (2 * i - 2));
    }
    return pai;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.7lf", countpai(n));
    return 0;
}
