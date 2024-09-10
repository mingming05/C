#include <stdio.h>

double togpa(int grade)
{
    double gpa;
    if (grade >= 95)
    {
        gpa = 4.1;
    }
    else if (grade >= 90)
    {
        gpa = 3.9;
    }
    else if (grade >= 85)
    {
        gpa = 3.7;
    }
    else if (grade >= 81)
    {
        gpa = 3.3;
    }
    else if (grade >= 78)
    {
        gpa = 3.0;
    }
    else if (grade >= 75)
    {
        gpa = 2.7;
    }
    else if (grade >= 72)
    {
        gpa = 2.3;
    }
    else if (grade >= 68)
    {
        gpa = 2.0;
    }
    else if (grade >= 64)
    {
        gpa = 1.7;
    }
    else if (grade >= 60)
    {
        gpa = 1.3;
    }
    else
    {
        gpa = 0.0;
    }
    return gpa;
}

int main()
{
    printf("请输入科目数量: ");
    int n;
    scanf("%d", &n);
    int grade[n];
    double credit[n];
    double gpa[n];
    double sumgrade = 0, sumcredit = 0, sumgpa = 0;
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d科成绩与学分: ", i + 1);
        scanf("%d", &grade[i]);
        scanf("%lf", &credit[i]);
        if(credit[i] == 0)
        {
            break;
        }
        gpa[i] = togpa(grade[i]);
        sumgrade += grade[i] * credit[i];
        sumcredit += credit[i];
        sumgpa += gpa[i] * credit[i];
    }
    printf("总成绩: %.2lf\n", sumgrade / sumcredit);
    printf("总绩点: %.2lf\n", sumgpa / sumcredit);
    return 0;
}

