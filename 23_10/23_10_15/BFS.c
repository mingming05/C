#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int bfs(int m, int n, int k)
{
    int queue[2][100000];
    int front = 0, rear = 0;
    int currentx = 0, currenty = 0;
    int visited[200][200];
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            visited[i][j] = 0;
        }
    }
    queue[0][rear] = 0;
    queue[1][rear] = 0;
    rear++;
    visited[0][0] = 1;
    while (front < rear)
    {
        currentx = queue[0][front];
        currenty = queue[1][front];
        front++;
        if (currentx == k || currenty == k)
        {
            return visited[currentx][currenty] - 1;
        }
        if (visited[m][currenty] == 0)
        {
            queue[0][rear] = m;
            queue[1][rear] = currenty;
            rear++;
            visited[m][currenty] = visited[currentx][currenty] + 1;
        }
        if (visited[currentx][n] == 0)
        {
            queue[0][rear] = currentx;
            queue[1][rear] = n;
            rear++;
            visited[currentx][n] = visited[currentx][currenty] + 1;
        }
        if (visited[0][currenty] == 0)
        {
            queue[0][rear] = 0;
            queue[1][rear] = currenty;
            rear++;
            visited[0][currenty] = visited[currentx][currenty] + 1;
        }
        if (visited[currentx][0] == 0)
        {
            queue[0][rear] = currentx;
            queue[1][rear] = 0;
            rear++;
            visited[currentx][0] = visited[currentx][currenty] + 1;
        }
        int pour = min(currenty, m - currentx);
        if (visited[currentx + pour][currenty - pour] == 0)
        {
            queue[0][rear] = currentx + pour;
            queue[1][rear] = currenty - pour;
            rear++;
            visited[currentx + pour][currenty - pour] = visited[currentx][currenty] + 1;
        }
        pour = min(currentx, n - currenty);
        if (visited[currentx - pour][currenty + pour] == 0)
        {
            queue[0][rear] = currentx - pour;
            queue[1][rear] = currenty + pour;
            rear++;
            visited[currentx - pour][currenty + pour] = visited[currentx][currenty] + 1;
        }
    }
    return -1;
}

int main()
{
    int m,n,k;
    scanf("%d%d%d", &m, &n, &k);
    printf("%d", bfs(m, n, k));
    return 0;
}