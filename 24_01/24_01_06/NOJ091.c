#include <stdio.h>

int fliptime(char *previous, char *next)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        if (previous[i] <= next[i])
        {
            sum += next[i] - previous[i];
        }
        else
        {
            sum += next[i] - previous[i] + 26;
        }
    }
    for (int i = 3; i < 7; i++)
    {
        if (previous[i] <= next[i])
        {
            sum += next[i] - previous[i];
        }
        else
        {
            sum += next[i] - previous[i] + 10;
        }
    }
    return sum;
}

int main()
{
    char previous[8], next[8];
    int sum = 0;
    scanf("%s", previous);
    scanf("%s", next);
    sum = fliptime(previous, next);
    printf("%d", sum);
    return 0;
}