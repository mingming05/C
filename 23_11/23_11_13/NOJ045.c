#include <stdio.h>

int Bubble(int carriage[], int n)
{
    int check;
    do
    {
        check = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (carriage[i] > carriage[i + 1])
            {
                int cache = carriage[i];
                carriage[i] = carriage[i + 1];
                carriage[i + 1] = cache;
                check = 1;
            }
        }
    } while (check);
}

int ifOK(int A, int B, int C, int chekin, int carryon)
{
    int OK = 0;
    int arr[3] = {A, B, C};
    int limit[2] = {chekin, carryon};
    Bubble(arr, 3);
    Bubble(limit, 2);
    if (

    )
        return OK;
}

int main()
{

    return 0;
}
