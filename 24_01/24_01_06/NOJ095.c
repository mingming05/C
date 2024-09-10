#include <stdio.h>
#include <math.h>
int main()
{
    double M1, M2;
    scanf("%lf %lf", &M1, &M2);
    printf("%.4lf\n", sqrt(M2 / M1));
    return 0;
}