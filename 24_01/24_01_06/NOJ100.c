#include <stdio.h>

int a[4];

int main()
{
    int n;
    scanf("%d", &n);
    a[0] = n / 10;
    n %= 10;
    a[1] = n / 5;
    n %= 5;
    a[2] = n / 2;
    n %= 2;
    a[3] = n;
    if(a[3])
    {
        printf("1=%d\n", a[3]);
    }
    if(a[2])
    {
        printf("2=%d\n", a[2]);
    }
    if(a[1])
    {
        printf("5=%d\n", a[1]);
    }
    if(a[0])
    {
        printf("10=%d\n", a[0]);
    }
    return 0;
}