#include <stdio.h>

int gcd(int a, int b) // 感谢欧几里得先生，虽然我看不懂，但我大受震撼
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void simplify(int *numerator, int *denominator)
{
    int a = *numerator, b = *denominator;
    int gcdvalue = gcd(a, b);
    a /= gcdvalue;
    b /= gcdvalue;
    *numerator = a;
    *denominator = b;
}

int main()
{
    int n1, n2, d1, d2;
    int numerator, denominator;
    scanf("%d/%d", &n1, &d1);
    scanf("%d/%d", &n2, &d2);
    numerator = n1 * d2 + n2 * d1;
    denominator = d1 * d2;
    simplify(&numerator, &denominator);
    printf("(%d/%d)+(%d/%d)=%d/%d\n", n1, d1, n2, d2, numerator, denominator);
    numerator = n1 * d2 - n2 * d1;
    denominator = d1 * d2;
    simplify(&numerator, &denominator);
    printf("(%d/%d)-(%d/%d)=%d/%d\n", n1, d1, n2, d2, numerator, denominator);
    numerator = n1 * n2;
    denominator = d1 * d2;
    simplify(&numerator, &denominator);
    printf("(%d/%d)*(%d/%d)=%d/%d\n", n1, d1, n2, d2, numerator, denominator);
    numerator = n1 * d2;
    denominator = d1 * n2;
    simplify(&numerator, &denominator);
    printf("(%d/%d)/(%d/%d)=%d/%d\n", n1, d1, n2, d2, numerator, denominator);
    return 0;
}
