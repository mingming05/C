#include <stdio.h>

int G(int n,int k)
{
    int returnvalue=0;
    for(int i=1;i<=n;i++)
    {
        returnvalue += k % i;
    }
    return returnvalue;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d",G(n,k));
    return 0;
}
