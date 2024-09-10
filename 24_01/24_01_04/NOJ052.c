#include <stdio.h>
#include <string.h>

int strToNum(char *str);
void numToStr(int n, char *result);

int main()
{
    char a[30] = "", b[30] = "";
    scanf("%s %s", a, b);

    // 定义一个足够大的数组来存储结果字符串
    char result[50] = "";

    // 将字符串转换为数字，计算结果，将结果转换为字符串
    numToStr(strToNum(a) + strToNum(b), result);

    // 打印结果
    puts(result);
    return 0;
}

int strToNum(char *str)
{
    if (strstr(str, "zero"))
        return 0;
    if (strstr(str, "ten"))
        return 10;
    if (strstr(str, "eleven"))
        return 11;
    if (strstr(str, "twelve"))
        return 12;
    if (strstr(str, "thirteen"))
        return 13;
    if (strstr(str, "fourteen"))
        return 14;
    if (strstr(str, "fifteen"))
        return 15;
    if (strstr(str, "sixteen"))
        return 16;
    if (strstr(str, "seventeen"))
        return 17;
    if (strstr(str, "eighteen"))
        return 18;
    if (strstr(str, "nineteen"))
        return 19;

    int unit = 0, decade = 0;
    if (strstr(str, "one"))
        unit = 1;
    if (strstr(str, "two"))
        unit = 2;
    if (strstr(str, "three"))
        unit = 3;
    if (strstr(str, "four"))
        unit = 4;
    if (strstr(str, "five"))
        unit = 5;
    if (strstr(str, "six"))
        unit = 6;
    if (strstr(str, "seven"))
        unit = 7;
    if (strstr(str, "eight"))
        unit = 8;
    if (strstr(str, "nine"))
        unit = 9;
    if (strstr(str, "twenty"))
        decade = 20;
    if (strstr(str, "thirty"))
        decade = 30;
    if (strstr(str, "forty"))
        decade = 40;
    if (strstr(str, "fifty"))
        decade = 50;
    if (strstr(str, "sixty"))
        decade = 60;
    if (strstr(str, "seventy"))
        decade = 70;
    if (strstr(str, "eighty"))
        decade = 80;
    if (strstr(str, "ninety"))
        decade = 90;
    return unit + decade;
}

void numToStr(int n, char *result)
{
    switch (n)
    {
    case 0:
        strcpy(result, "zero");
        return;
    case 11:
        strcpy(result, "eleven");
        return;
    case 12:
        strcpy(result, "twelve");
        return;
    case 13:
        strcpy(result, "thirteen");
        return;
    case 14:
        strcpy(result, "fourteen");
        return;
    case 15:
        strcpy(result, "fifteen");
        return;
    case 16:
        strcpy(result, "sixteen");
        return;
    case 17:
        strcpy(result, "seventeen");
        return;
    case 18:
        strcpy(result, "eighteen");
        return;
    case 19:
        strcpy(result, "nineteen");
        return;
    default:
        break;
    }

    int decade = (n / 10) % 10, unit = n % 10;
    switch (decade)
    {
    case 2:
        strcpy(result, "twenty");
        break;
    case 3:
        strcpy(result, "thirty");
        break;
    case 4:
        strcpy(result, "forty");
        break;
    case 5:
        strcpy(result, "fifty");
        break;
    case 6:
        strcpy(result, "sixty");
        break;
    case 7:
        strcpy(result, "seventy");
        break;
    case 8:
        strcpy(result, "eighty");
        break;
    case 9:
        strcpy(result, "ninety");
        break;
    default:
        break;
    }

    if (decade && unit)
        strcat(result, "-");

    switch (unit)
    {
    case 1:
        strcat(result, "one");
        break;
    case 2:
        strcat(result, "two");
        break;
    case 3:
        strcat(result, "three");
        break;
    case 4:
        strcat(result, "four");
        break;
    case 5:
        strcat(result, "five");
        break;
    case 6:
        strcat(result, "six");
        break;
    case 7:
        strcat(result, "seven");
        break;
    case 8:
        strcat(result, "eight");
        break;
    case 9:
        strcat(result, "nine");
        break;
    default:
        break;
    }
}
