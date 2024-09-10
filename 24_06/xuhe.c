#include <stdio.h>

int main()
{
    int counter[26] = {0};
    char c;
    while ((c = getchar()) != '\n')
    {
        for (int i = 0; i < 26; i++)
        {
            if (c == 'a' + i || c == 'A' + i)
            {
                counter[i]++;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (counter[i] != 0)
        {
            printf("'%c':%d\n", 'A' + i, counter[i]);
        }
    }
    return 0;
}