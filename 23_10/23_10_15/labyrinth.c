#include <stdio.h>

int labyrinth(int column, int row, int maze[column][row])
{
    int visited[200][200];
    int queue[100000][2];
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            visited[i][j] = 0;
        }
    }
    int front = 0, rear = 0;
    queue[rear][0] = 0;
    queue[rear][1] = 0;
    rear++;
    visited[0][0] = 1;
    while (front < rear)
    {
        int current_column = queue[front][0];
        int current_row = queue[front][1];
        front++;
        if (current_column == column - 1 && current_row == row - 1)
        {
            return visited[current_column][current_row] - 1;
        }
        if (visited[current_column + 1][current_row] == 0 && current_column + 1 < column)
        {
            if (maze[current_column + 1][current_row] == 0)
            {
                queue[rear][0] = current_column + 1;
                queue[rear][1] = current_row;
                rear++;
            }
            visited[current_column + 1][current_row] = visited[current_column][current_row] + 1;
        }
        if (visited[current_column][current_row + 1] == 0 && current_row + 1 < row)
        {
            if (maze[current_column][current_row + 1] == 0)
            {
                queue[rear][0] = current_column;
                queue[rear][1] = current_row + 1;
                rear++;
            }
            visited[current_column][current_row + 1] = visited[current_column][current_row] + 1;
        }
        if (visited[current_column - 1][current_row] == 0 && current_column - 1 >= 0)
        {
            if (maze[current_column - 1][current_row] == 0)
            {
                queue[rear][0] = current_column - 1;
                queue[rear][1] = current_row;
                rear++;
            }
            visited[current_column - 1][current_row] = visited[current_column][current_row] + 1;
        }
        if (visited[current_column][current_row - 1] == 0 && current_row - 1 >= 0)
        {
            if (maze[current_column][current_row - 1] == 0)
            {
                queue[rear][0] = current_column;
                queue[rear][1] = current_row - 1;
                rear++;
            }
            visited[current_column][current_row - 1] = visited[current_column][current_row] + 1;
        }
    }
    return -1;
}

int main()
{
    int column, row;
    scanf("%d %d", &column, &row);
    int maze[column][row];
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    printf("%d", labyrinth(column, row, maze));
    return 0;
}
