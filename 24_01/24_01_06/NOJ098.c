#include <stdio.h>
#include <string.h>
void caozuo(char *a)
{
    int n = strlen(a);
    int sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 0; i < n / 2 - 1; i++)
        {
            if (a[i] < a[i + 1])
            {
                char temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted = 0;
            }
        }
    }
    int start = (n + 1) / 2;
    int end = n - 1;
    while (start < end)
    {
        char temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char a[1001];
    scanf("%s", a);
    caozuo(a);
    printf("%s\n", a);
    return 0;
}
