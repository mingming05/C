#include <stdio.h>
#include <math.h>

int numofdec(double dec)
{
    int count = 0;
    double integer = floor(dec);
    while (dec - integer != 0.0)
    {
        count += 1;
        dec *= 10.0;
        integer = floor(dec);
    }
    return count;
}

int gcd(int a, int b)//感谢欧几里得先生，虽然我看不懂，但我大受震撼
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
    double decimal;
    scanf("%lf", &decimal);
    int Denominator = pow(10, numofdec(decimal));
    int Numerator = (int)(decimal * Denominator);
    simplify(&Numerator, &Denominator);
    printf("%d/%d", Numerator, Denominator);
    return 0;
}
