#include <stdio.h>
#include <math.h>

double windChill(double velocity, double temperature)
{
    double windChill = 13.12 + 0.6215 * temperature - 11.37 * pow(velocity, 0.16) + 0.3965 * temperature * pow(velocity, 0.16);
    return windChill;
}

int main()
{
    double velocity, temperature;
    scanf("%lf%lf", &velocity, &temperature);
    printf("%.0lf\n", windChill(velocity, temperature));
    return 0;
}
