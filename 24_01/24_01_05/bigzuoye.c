/* 2023300074 HC202304  杨力畅 */
#include <stdio.h>
#include <string.h>
char Location[1000][1000], start_location[1000], end_location[1000];
int count = 0, Price[1000][1000], start = -1, end = -1;
int result_path[1000]; // 用来存储迪杰斯特拉算法得到的从起点到终点的最短路径
int length_path = 0;   // 存储迪杰斯特拉算法得到的最短路径的长度
int distance_djstl;
void get_Location()
{
    printf("请输入当天各车程历经地点(请把起点放在首位，以空格分隔，以0结束)：\n");
    char location[100];
    scanf("%s", &location);
    while (strcmp(location, "0") != 0)
    {
        strcpy(Location[count], location);
        count++;
        scanf("%s", &location);
    }
    printf("\n");
}
void get_Price() // 简化成两地之间来回的车片价格相等
{
    int price = 0;
    printf("请依次输入各个地点之间的车票价格（若两地之间没有车程则输入-1）:\n");
    for (int i = 0; i < count; i++)
    {
        Price[i][i] = 0;
        for (int j = i + 1; j < count; j++)
        {
            printf("%s和%s之间:  ", Location[i], Location[j]);
            scanf("%d", &price);
            if (price == -1)
            {
                Price[i][j] = 1000000;
                Price[j][i] = 1000000;
            }
            else
            {
                Price[i][j] = price;
                Price[j][i] = price;
            }
        }
    }
}
void get_StartAndEnd()
{
    printf("请输入您的行程的出发地和目的地：\n");
    printf("出发地：");
    scanf("%s", &start_location);
    printf("目的地：");
    scanf("%s", &end_location);
    for (int p = 0; p < count; p++)
    {
        if (strcmp(Location[p], start_location) == 0)
        {
            start = p;
        }
        if (strcmp(Location[p], end_location) == 0)
        {
            end = p;
        }
    }
    if (start == -1 || end == -1)
    {
        printf("输入有误！请输入正确的地点名！\n");
        get_StartAndEnd();
    }
}
void Calculate_djstl() // 使用迪杰斯特拉算法计算总票价最便宜时的购票方案
{
    int visited[1000] = {0};       // 记录各点是否已经遍历
    int distance[1000] = {100000}; // 记录目前时刻起点到个点的最短距离
    int path[1000];                // 记录到各点的最短路径
    int re_path[1000];
    for (int i = 0; i < count; i++)
    {
        distance[i] = Price[start][i];
    }
    visited[start] = 1;
    int Min_location = start;
    for (int a = 0; a < count; a++)
    {
        int Min_distance = 100000;
        for (int b = 0; b < count; b++) // 遍历各个点找到目前与起点距离最短的点为Min_location
        {
            if (visited[b] == 0 && distance[b] < Min_distance)
            {
                Min_location = b;
                Min_distance = distance[b];
            }
        }
        visited[Min_location] = 1;
        for (int k = 0; k < count; k++) // 从目前最短点Min_location出发更新距离
        {
            if (visited[k] == 0 && (distance[Min_location] + Price[Min_location][k]) < distance[k])
            {
                distance[k] = distance[Min_location] + Price[Min_location][k];
                path[k] = Min_location; // 记录了目前到各点最短的上一个点是什么
            }
        }
    }
    distance_djstl = distance[end];
    int current = end;
    while (current != start)
    {
        re_path[length_path] = current;
        current = path[current];
        length_path++;
    }
    re_path[length_path] = start;
    length_path++;
    for (int i = 0; i < (length_path); i++)
    {
        result_path[i] = re_path[(length_path)-i - 1];
    }
}

void print_path(int path[], int len_path)
{
    if (len_path > 2)
    {
        printf("若不考虑中转次数限制，价格最低的购票方案为：");
        for (int i = 0; i < len_path; i++)
        {
            printf("%s", Location[path[i]]);
            if (i < (len_path)-1)
            {
                printf("-->");
            }
        }
        printf("\n");
        printf("此方案的价格为：%d\n", distance_djstl);
    }
    else
    {
        printf("价格最低的购票方案为：");
        for (int i = 0; i < len_path; i++)
        {
            printf("%s", Location[path[i]]);
            if (i < (len_path)-1)
            {
                printf("-->");
            }
        }
        printf("\n");
        printf("此方案的价格为：%d\n", distance_djstl);
    }
}
int DFS_result[1000];
int count_dfs = 0;
int DFS_path[1000];
int min_price = 100000;

// 队列结构体
typedef struct
{
    int data[1000];        // 记录后续要访问的结点
    int visited_dfs[1000]; // 记录对这一条路径来说哪一个点已经访问过了
    int path[1000];        // 记录父节点
    int pathLength;        // 记录路径长度，防止其超出用户限制的最大中转次数
    int price;             // 记录此路径的价格
    int front, rear;       // 辅助data数组来增减结点
} Queue;

// 创建队列
Queue *createQueue() // 初始化创造一个队列
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->pathLength = 1;
    queue->price = 0;
    for (int i = 0; i < 1000; i++) // 将队列的visited数组全部初始化为0；
    {
        queue->visited_dfs[i] = 0;
    }
    return queue;
}
// 创建一个和原队列（queue）一摸一样的子队列（sonqueue）
Queue *create_sonqueue(Queue *queue)
{
    // printf("create111\n");
    Queue *son_queue = (Queue *)malloc(sizeof(Queue));
    son_queue->front = queue->front;
    son_queue->rear = queue->rear;
    son_queue->pathLength = queue->pathLength;
    son_queue->price = queue->price;
    memcpy(son_queue->visited_dfs, queue->visited_dfs, sizeof(queue->visited_dfs));
    memcpy(son_queue->data, queue->data, sizeof(queue->data));
    memcpy(son_queue->path, queue->path, sizeof(queue->path));
    return son_queue;
}

// 检查队列是否为空
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

// 入队（将结点加入到队列中）
void enqueue(Queue *queue, int item)
{
    if (queue->rear == 10000)
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->data[++queue->rear] = item;
}

// 出队（删除队首结点并且返回了队首节点的值）
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->data[queue->front++];
    if (queue->front > queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    return item; // 返回队首结点的值
}

// 执行深度优先搜索
int DFS(Queue *queue, int k) // k是用户输入的最大中转次数的限制
{
    if (queue->visited_dfs[end] == 1) // 退出条件，当遍历到终点时退出
    {
        if (queue->price < min_price) // 用来找寻最短路径
        {
            min_price = queue->price;
            for (int j = 0; j < count; j++)
            {
                DFS_path[j] = queue->path[j];
            }
        }
        return 0;
    }
    if (queue->pathLength >= k + 2) // 当路径长度超出给定的限制时退出遍历
    {
        return 0;
    }
    int current, i, j;
    current = dequeue(queue); // 删除队列的首结点，并提取为current，即目前路径到达的结点
    for (i = 0; i < count; i++)
    {
        if (queue->visited_dfs[i] == 0) // 若此结点没被访问过
        {
            Queue *sonqueue = create_sonqueue(queue);        // 创建queue队列的子队列
            sonqueue->visited_dfs[i] = 1;                    // 标记子队列已经访问过了此节点
            enqueue(sonqueue, i);                            // 将此结点加入到子队列的data中
            sonqueue->path[i] = current;                     // path数组是用来记录各个结点的父节点的
            sonqueue->pathLength = sonqueue->pathLength + 1; // 更新路径长度
            sonqueue->price += Price[current][i];            // 更新路径的价格
            DFS(sonqueue, k);                                // 继续往下深搜，直到满足退出条件退出遍历
        }
    }
    for (int i = 0; i < count; i++) // 将父队列（queue）全部结点更新为已访问过，防止出现回溯时重复访问的情况
    {
        queue->visited_dfs[i] = 1;
    }
}
void Findshortest(int k) // 根据用户输入的最大中转次数k来输出价格最低的购票方案
{
    int dfs_current = end;
    int length_dfspath = 0;
    int re_dfspath[1000];
    int result_dfspath[1000];
    while (dfs_current != start)
    {
        re_dfspath[length_dfspath] = dfs_current;
        dfs_current = DFS_path[dfs_current];
        length_dfspath++;
    }
    re_dfspath[length_dfspath] = start;
    length_dfspath++;
    for (int i = 0; i < (length_dfspath); i++)
    {
        result_dfspath[i] = re_dfspath[(length_dfspath)-i - 1];
    }
    printf("若要求中转次数不超过%d次，价格最低的购票方案为：", k);
    for (int i = 0; i < (length_dfspath); i++)
    {
        printf("%s", Location[result_dfspath[i]]);
        if (i < length_dfspath - 1)
        {
            printf("->");
        }
    }
    printf("\n");
    printf("此方案的价格为：%d\n", min_price);
}
void update() // 重置各变量数组
{
    for (int i = 0; i < 1000; i++)
    {
        DFS_path[i] = 0;
        DFS_result[i] = 0;
        count_dfs = 0;
        min_price = 100000;
    }
}
void Calculate_dfs() // 通过循环不断输入最大中转次数，直到用户输入-1退出程序
{
    printf("若您对中转换乘次数有要求，请输入您期望的换乘次数不超过（退出请输入-1）：");
    int k;
    scanf("%d", &k);

    while (k != -1)
    {
        Queue *queue = createQueue();
        enqueue(queue, start);
        queue->visited_dfs[start] = 1;
        DFS(queue, k);
        Findshortest(k);
        update();
        printf("若您对中转换乘次数有要求，请输入您期望的换乘次数不超过（退出请输入-1）：");
        scanf("%d", &k);
    }
    return;
}
int main()
{
    get_Location();
    get_Price();
    get_StartAndEnd();
    Calculate_djstl();
    print_path(result_path, length_path);
    Calculate_dfs();
}
