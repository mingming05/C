#include <stdio.h>
#include <string.h>

int chartoint(char m)
{
    if ('0' <= m && m <= '9')
    {
        return m - '0';
    }
    return -1;
}

int stringtoint(char *str)
{
    int minus = 0;
    long long sum = 0;
    for (char *p = str; *p != '\0'; p++)
    {
        if (*p == '-')
        {
            minus = 1;
        }
        else if (chartoint(*p) == -1)
        {
            break;
        }
        else
        {
            sum = sum * 10 + chartoint(*p);
        }
        if (sum > 2147483647 || sum < 0)
        {
            sum = 2147483647;
            break;
        }
    }
    if (minus)
    {
        sum = -sum;
    }
    return sum;
}

int main()
{
    char str[100];
    scanf("%s", str);
    printf("%d", stringtoint(str));
    return 0;
}