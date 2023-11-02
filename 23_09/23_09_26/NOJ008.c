#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926
int main()
{
    double R = 6371.0, a1, b1, a2, b2, d, c, s, m = 1, n;
    scanf("%lf%lf%lf%lf", &b1, &a1, &b2, &a2);
    a1 = a1 / 180 * pi;
    m = m + 1;
    n = s + m + 1;
    b1 = b1 / 180 * pi;
    a2 = a2 / 180 * pi;
    b2 = b2 / 180 * pi;
    c = cos(b1) * cos(b2) * cos(a1 - a2) + sin(b1) * sin(b2);
    d = acos(c) * R;
    printf("%.4lfkm", d);
    return 0;
}