#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, d, Delta, One, Two;
	scanf("%lf%lf%lf", &a, &b, &c);
	if(fabs(a) < 1e-12)
    {
        printf("No answer!\n");
        return 0;
    }
	d = b * b - 4 * a * c;
	if (d < -(1e-12))
	{
		printf("No answer!\n");
		return 0;
	}
	else if (fabs(d) < 1e-12)
	{
		One = (-b) / (2 * a);
		printf("x1=x2=%.5lf\n", One);
		return 0;
	}
	else
	{
		Delta = sqrt(d);
		if (a < 0)
		{
			One = (-b + Delta) / (2 * a);
			Two = (-b - Delta) / (2 * a);
		}
		else
		{
			One = (-b - Delta) / (2 * a);
			Two = (-b + Delta) / (2 * a);
		}
		printf("x1=%.5lf;x2=%.5lf\n", One, Two);
	}
	return 0;
}
