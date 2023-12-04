#include <stdio.h>

int ifOK(int A, int B, int C, int checkin, int carryon)
{
    if (A + B <= checkin && C <= carryon)
    {
        return 1;
    }
    if (A + C <= checkin && B <= carryon)
    {
        return 1;
    }
    if (B + C <= checkin && A <= carryon)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int A, B, C, checkin, carryon;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d", &A, &B, &C, &checkin, &carryon);
        if (ifOK(A, B, C, checkin, carryon))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
