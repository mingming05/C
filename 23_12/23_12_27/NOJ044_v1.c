/*#include <stdio.h>

int perfectMatrix(int i, int j, int k, int l, int **matrix[][])
{
}

int countPerfectMatrix(int n, int m, int **matrix[][])
{
    int count = 0;
    if (perfectMatrix(0, 0, n - 1, m - 1, matrix))
    {
        count++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = 0; i < m; i++)
            {
                for (int l = k + 1; l < m - 1; j++)
                {
                    if (perfectMatrix(i, j, k, l, matrix))
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    return 0;
}
*/

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 301

int arr[MAXSIZE][MAXSIZE] = {0};
int preSum[MAXSIZE][MAXSIZE] = {0};

void prefix(int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + arr[i][j]; // 上面的元素加上左边的元素减去左上角的元素再加上当前元素
        }
    }
}

int getSum(int x1, int x2, int y1, int y2)
{
    return preSum[x2][y2] - preSum[x1 - 1][y2] - preSum[x2][y1 - 1] + preSum[x1 - 1][y1 - 1];
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
    prefix(n, m);
    printf("%d", perfectNum(n, m));
    return 0;
}
