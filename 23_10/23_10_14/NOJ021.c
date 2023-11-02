#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; n > i; i++)
    {
        n -= i;
    }
    printf("%d", n);
    return 0;
}
