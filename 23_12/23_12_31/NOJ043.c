#include <stdio.h>

int main()
{
    int l3s2[4] = {0, 5, 3, 1};
    int n, x1, x2, x3, x4, x5, x6, s2, s1;
    while (1)
    {
        scanf("%d %d %d %d %d %d", &x1, &x2, &x3, &x4, &x5, &x6);
        if ((x1 + x2 + x3 + x4 + x5 + x6) == 0)
        {
            break;
        }
        n = (x3 + 3) / 4 + x4 + x5 + x6;
        s2 = 5 * x4 + l3s2[x3 % 4];
        if (x2 > s2)
        {
            n += (x2 - s2 + 8) / 9;
        }
        s1 = 36 * n - 36 * x6 - 25 * x5 - 16 * x4 - 9 * x3 - 4 * x2;
        if (x1 > s1)
        {
            n += (x1 - s1 + 35) / 36;
        }
        printf("%d\n", n);
    }
    return 0;
}