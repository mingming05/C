#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...)
{
    va_list valist;
    int sum = 0;
    va_start(valist, num);
    for (int i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    va_end(valist);
    return sum;
}

int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d\n", sum(3, a, b, 0) - sum(5, c, d, e, f, 0));
    return 0;
}
