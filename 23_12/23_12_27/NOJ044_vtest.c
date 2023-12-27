#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 301

int arr[MAXSIZE][MAXSIZE] = {0};

int getSum(int x1, int x2, int y1, int y2)
{
    int sum = 0;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

bool isPerfect(int x1, int x2, int y1, int y2)
{
    int outer = getSum(x1, x2, y1, y2), inner;
    int len = 2 * (x2 - x1 + y2 - y1);
    if ((x2 - x1) == 1 || (y2 - y1) == 1)
        inner = 0;
    else
        inner = getSum(x1 + 1, x2 - 1, y1 + 1, y2 - 1);

    if (inner != 1 && inner != 0 && inner != -1)
        return false;
    if ((outer - inner) != len)
        return false;
    return true;
}

int perfectNum(int n, int m)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 1; k + i <= n && k + j <= m; k++)
            {
                if (arr[i][k + j] == -1 || arr[k + i][j] == -1)
                {
                    break;
                }
                
                if (isPerfect(i, i + k, j, j + k))
                {
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0)
            {
                arr[i][j] = -1;
            }
        }
    }
    printf("%d", perfectNum(n, m));
    return 0;
}
