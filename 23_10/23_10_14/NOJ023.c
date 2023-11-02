#include <stdio.h>

int visited[101][101]; // 用整数数组标记已经访问过的状态

int min(int a, int b)
{
    return a < b ? a : b;
}

int bfs(int m, int n, int k)
{
    int queue[100000][2];
    int front = 0, rear = 0;
    queue[rear][0] = 0; // 初始时两个桶都是空的
    queue[rear][1] = 0;
    rear++;
    visited[0][0] = 1;

    while (front < rear)
    {
        int current_x = queue[front][0];
        int current_y = queue[front][1];
        front++;

        if (current_x == k || current_y == k)
        {
            return visited[current_x][current_y] - 1;
        }

        // 倒满x或y
        if (visited[m][current_y] == 0)
        {
            queue[rear][0] = m;
            queue[rear][1] = current_y;
            rear++;
            visited[m][current_y] = visited[current_x][current_y] + 1;
        }
        if (visited[current_x][n] == 0)
        {
            queue[rear][0] = current_x;
            queue[rear][1] = n;
            rear++;
            visited[current_x][n] = visited[current_x][current_y] + 1;
        }

        // 倒空x或y
        if (visited[0][current_y] == 0)
        {
            queue[rear][0] = 0;
            queue[rear][1] = current_y;
            rear++;
            visited[0][current_y] = visited[current_x][current_y] + 1;
        }
        if (visited[current_x][0] == 0)
        {
            queue[rear][0] = current_x;
            queue[rear][1] = 0;
            rear++;
            visited[current_x][0] = visited[current_x][current_y] + 1;
        }

        // x向y倒水
        int pour = min(current_x, n - current_y);
        if (visited[current_x - pour][current_y + pour] == 0)
        {
            queue[rear][0] = current_x - pour;
            queue[rear][1] = current_y + pour;
            rear++;
            visited[current_x - pour][current_y + pour] = visited[current_x][current_y] + 1;
        }

        // y向x倒水
        pour = min(current_y, m - current_x);
        if (visited[current_x + pour][current_y - pour] == 0)
        {
            queue[rear][0] = current_x + pour;
            queue[rear][1] = current_y - pour;
            rear++;
            visited[current_x + pour][current_y - pour] = visited[current_x][current_y] + 1;
        }
    }
    return -1;
}

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    printf("%d", bfs(m, n, k));
    return 0;
}
