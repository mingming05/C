#include <stdio.h>

void printBinaryFormat(int n)
{
    int binary[100];
    int ncopy = n;
    int i = 0;
    do
    {
        binary[i] = ncopy % 2;
        ncopy /= 2;
        i++;
    } while (ncopy);
    for (int j = i - 1; j >= 0; j--)
    {
        if (binary[j] == 1)
        {
            printf("2");
            if (j == 0)
            {
                printf("(0)");
            }
            if (j == 2)
            {
                printf("(2)");
            }
            if (j >= 3)
            {
                printf("(");
                printBinaryFormat(j);
                printf(")");
            }
            int count = 0;
            for (int k = j - 1; k >= 0; k--)
            {
                if (binary[k] == 1)
                {
                    count++;
                }
            }
            if (count)
            {
                printf("+");
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printBinaryFormat(n);
    return 0;
}
