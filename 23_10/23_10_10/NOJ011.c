#include <stdio.h>

int ifRotate(int num)
{
    int digit = 1;
    int numcache = num;
    while (numcache / 10 != 0)
    {
        numcache /= 10;
        digit += 1;
    }
    numcache = num;
    int numarr[digit];
    for (int i = 0; i < digit; i++)
    {
        numarr[i] = numcache % 10;
        numcache /= 10;
    }
    int isRoatatable = 0;
    if (digit == 1)
    {
        if (num == 0 || num == 1 || num == 8)
        {
            isRoatatable = 1;
        }
    }
    else
    {
        if (digit % 2 == 0)
        {

            for (int i = 0; i < digit / 2; i++)
            {
                if (((numarr[i] == numarr[digit - i - 1]) && (numarr[i] == 0 || numarr[i] == 1|| numarr[i] == 8)) || (numarr[i] == 6 && numarr[digit - i - 1] == 9) || (numarr[i] == 9 && numarr[digit - i - 1] == 6))
                {
                    isRoatatable = 1;
                }
            }
        }
        else
        {
            if (numarr[digit / 2] == 0 || numarr[digit / 2] == 1 || numarr[digit / 2] == 8)
            {
                for (int i = 0; i < digit / 2; i++)
                {
                    if (((numarr[i] == numarr[digit - i - 1]) && (numarr[i] == 0 || numarr[i] == 1 || numarr[i] == 8)) || (numarr[i] == 6 && numarr[digit - i - 1] == 9) || (numarr[i] == 9 && numarr[digit - i - 1] == 6))
                    {
                        isRoatatable = 1;
                    }
                }
            }
        }
    }
    return isRoatatable;
}

int main()
{
    int num;
    scanf("%d", &num);
    if (ifRotate(num))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
