#include <stdio.h>

int main()
{
    int a, b;
    int product = 0;
    scanf("%d%d", &a, &b);
    while (a >= 1)
    {
        printf("%d ", a);
        printf("%d\n", b);
        if (a % 2 == 1)
        {
            product += b;
        }
        a = a / 2;
        b = b * 2;
    }
    printf("%d ", product);
    return 0;
}
