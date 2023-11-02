#include <stdio.h>

int main()
{
    char name[21];
    char max_name[21];
    int n;
    int score, max_score = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%20s", &score, &name);
        if (score > max_score)
        {
            max_score = score;
            for (int i = 0; i < 21; i++)
            {
                max_name[i] = name[i];
            }
        }
    }
    printf("%s", max_name);
    return 0;
}
