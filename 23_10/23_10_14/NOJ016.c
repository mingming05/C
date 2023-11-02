#include <stdio.h>

/*不行，速度太慢
int main()
{
    long long unsigned int a, b, m, c = 1;
    scanf("%ll%llu%llu", &a, &b, &m);
    for (int i = 0; i < b; i++)
    {
        c = (c * a) % m;
    }
    printf("%llu", c);
    return 0;
}
*/
//下面是网上的方法，我看不懂，但我大受震撼
long long Mode(long long a, long long b, long long mode)
{
    long long sum = 1;
    while (b > 0) 
    {
        if (b % 2 == 1) 
        {
            sum = (sum * a) % mode;
        }
        b /= 2;
        a = (a * a) % mode;
    }
    return sum;
}

int main()
{
    long long int a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long result = Mode(a, b, c);
    printf("%lld", result);
    return 0;
}
