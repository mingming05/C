#include <stdio.h>
#include <math.h>

typedef struct NOJ096
{
    char name[10];
    int x, y;
} flight;

int main()
{
    int n;
    scanf("%d", &n);
    flight flights[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", flights[i].name, &flights[i].x, &flights[i].y);
    }
    flight *p1, *p2, *p1min, *p2min;
    double min = 0.0, distance;
    for (p1 = &flights[0]; p1 < &flights[n]; p1++)
    {
        for (p2 = p1 + 1; p2 < &flights[n]; p2++)
        {
            distance = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
            if (min >= distance || min == 0.0)
            {
                min = distance;
                p1min = p1;
                p2min = p2;
            }
        }
    }
    printf("%s-%s %.4lf\n", p1min->name, p2min->name, min);
    return 0;
}