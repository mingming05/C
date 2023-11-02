#include <stdio.h>

int sumofmultiplesof3or5(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int testarr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &testarr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n", sumofmultiplesof3or5(testarr[i]));
    }
    return 0;
}
