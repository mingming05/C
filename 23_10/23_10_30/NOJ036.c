#include <stdio.h>

void printCollatz(int n)
{
    printf("%d ", n);
    while (n > 2)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            printf("%d ", n);
        }
        else
        {
            n = 3 * n + 1;
            printf("%d ", n);
        }
    }
    printf("1");
}
//在ab边上任取一点p，ap长度为X。从该点水平方向向右射入一束红光，接下来它遇到镜子或者自己的轨迹，都会反射。可以证明，光最后是从p点射出的。编程求光线轨迹的总长度。
int main()
{
    int n;
    scanf("%d", &n);
    printCollatz(n);
    return 0;
}
