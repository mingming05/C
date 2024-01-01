#include <stdio.h>
typedef struct
{
    double a;
    double b;
} Linear;

Linear linreg(int x[], int y[], int n)
{
    Linear ans;
    double sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;
    for (int i = 0; i < n; i++)
    {
        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
    }
    double meanx = sumx / n;
    double meany = sumy / n;
    ans.b = (sumxy - n * meanx * meany) / (sumx2 - n * meanx * meanx);
    ans.a = meany - ans.b * meanx;
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
        y[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    Linear ans = linreg(x, y, n);
    printf("Y=%.4lf", ans.a);
    if (ans.b < 0)
    {
        printf("%.4lf*X", ans.b);
    }
    else if(ans.b > 0)
    {
        printf("+%.4lf*X", ans.b);
    }
    return 0;
}