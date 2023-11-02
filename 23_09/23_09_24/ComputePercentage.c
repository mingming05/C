#include <stdio.h>

int main()
{
    int n, a = 0, b = 0, c = 0, d = 0;
    scanf("%d", &n);
    int patients[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &patients[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (patients[i] <= 18)
        {
            a += 1;
        }
        else if (patients[i] <= 35)
        {
            b += 1;
        }
        else if (patients[i] <= 60)
        {
            c += 1;
        }
        else
        {
            d += 1;
        }
    }
    double ap = 100.0 * a / n;
    double bp = 100.0 * b / n;
    double cp = 100.0 * c / n;
    double dp = 100.0 * d / n;
    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%\n", ap, bp, cp, dp);
    return 0;
}