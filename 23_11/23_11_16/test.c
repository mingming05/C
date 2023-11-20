#include <stdio.h>

void swap(int **p1, int **p2)
{
    int *temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a, b;
    int *p1 = &a, *p2 = &b;
    int **pp1 = &p1, **pp2 = &p2;
    scanf("%d%d", &a, &b);
    swap(pp1, pp2);
    printf("%d %d\n", **pp1, **pp2);
    return 0;
}