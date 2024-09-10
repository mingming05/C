#include <stdio.h>
#include <math.h>

double mach(double v, double t)
{
    double c = 331.3 * sqrt(1 + t / 273.15);
    return v / (3.6 * c);
}

void printmach(double mach)
{
    if (mach < 0.8)
        printf("subsonic\n");
    else if (mach >= 0.8 && mach <= 1.2)
        printf("transonic\n");
    else if (mach > 1.2 && mach < 5.0)
        printf("supersonic\n");
    else if (mach >= 5.0)
        printf("hypersonic\n");
}

int main()
{
    double v, t;
    scanf("%lf%lf", &v, &t);
    double machresult = mach(v, t);
    printf("%.3lf ", machresult);
    printmach(mach(v, t));
    return 0;
}