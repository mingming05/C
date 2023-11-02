#include <stdio.h>
#include <math.h>

int convertRGBtoHSV(double *R, double *G, double *B)
{
    double H, S, V;
    double max, min;
    max = *R > *G ? *R : *G;
    max = max > *B ? max : *B;
    min = *R < *G ? *R : *G;
    min = min < *B ? min : *B;
    V = max / 255;
    if (max == 0)
    {
        S = 0;
    }
    else
    {
        S = (max - min) / max;
    }
    if (max == *R)
    {
        H = 60 * (*G - *B) / (max - min);
    }
    else if (max == *G)
    {
        H = 60 * (*B - *R) / (max - min) + 120;
    }
    else
    {
        H = 60 * (*R - *G) / (max - min) + 240;
    }
    if (H < 0)
    {
        H += 360;
    }
    *R = H;
    *G = 100 * S;
    *B = 100 * V;
    return 0;
}

int main()
{
    double R, G, B;
    scanf("%lf%lf%lf", &R, &G, &B);
    convertRGBtoHSV(&R, &G, &B);
    printf("%.4lf,%.4lf%%,%.4lf%%\n", R, G, B);
    return 0;
}
