#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if(n==2||n==3)
    {
        return 1;
    }
    int maximum = sqrt(n);
    for (int i = 2; i <= maximum; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int countPrime(int a, int b)
{
    if(a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if(isPrime(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",countPrime(a,b));
    return 0;
}