#include <stdio.h>
#include <stdlib.h>

int primenum(int n)
{
    int num = 0;
    int *isprime = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        isprime[i] = 1;
        visited[i] = 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (isprime[i] && !visited[i])
        {
            for (int j = i + i; j < n; j += i)
            {
                isprime[j] = 0;
                visited[j] = 1;
            }
            visited[i] = 1;
        }
    }
    for (int i = 2; i < n; i++)
    {
        num += isprime[i];
    }
    free(isprime);
    free(visited);
    return num;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", primenum(n));
    return 0;
}