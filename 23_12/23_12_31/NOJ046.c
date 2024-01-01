#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int matrix[n][m];
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    if ((n * m) / count >= 20 || count == n || count == m)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}