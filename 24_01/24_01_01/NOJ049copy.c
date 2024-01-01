#include <stdio.h>
#include <stdbool.h>

#define NUM (int)1e7 + 1

static bool isSieved[NUM];
static int prime[NUM];

int main()
{
    int n, k = 0;
    scanf("%d", &n);
    isSieved[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (!isSieved[i])
        {
            prime[++k] = i;
        }
        for (int j = 1; prime[j] * i <= n; ++j)
        {
            isSieved[prime[j] * i] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    printf("%d", k);
}