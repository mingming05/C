#include <stdio.h>

int Bubble(int carriage[], int n)
{
    int sum = 0, check, a;
    do
    {
        check = 0;
        a = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (carriage[i] > carriage[i + 1])
            {
                int cache = carriage[i];
                carriage[i] = carriage[i + 1];
                carriage[i + 1] = cache;
                sum += 1;
                a += 1;
            }
        }
        if (a == 0)
        {
            check = 0;
        }
        else
        {
            check = 1;
        }

    } while (check);
    return sum;
}