#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    FILE *fp = fopen("rr.dat", "wb");
    for (int i = 1; i <= n; i++)
    {
        fprintf(fp, "%.6lf\n", sqrt(i));
    }
    fclose(fp);
    FILE *fp2 = fopen("rr.dat", "rb");
    for (int i = 0; i <= n; i++)
    {
        double temp;
        fscanf(fp2, "%lf", &temp);
        printf("%.6lf ", temp);
    }
    return 0;
}