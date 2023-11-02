#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("%d,%d,%d", sizeof(char), -128, 127);
        break;
    case 2:
        printf("%d,%d,%d", sizeof(unsigned char), 0, 255);
        break;
    case 3:
        printf("%d,%d,%d", sizeof(short), -32768, 32767);
        break;
    case 4:
        printf("%d,%d,%d", sizeof(unsigned short), 0, 65535);
        break;
    case 5:
        printf("%d,%d,%d", sizeof(int), -2147483648, 2147483647);
        break;
    case 6:
        printf("%d,%d,%d", sizeof(unsigned int), 0, 4294967295);
        break;
    case 7:
        printf("%d,%d,%d", sizeof(long), -2147483648, 2147483647);
        break;
    case 8:
        printf("%d,%d,4294967295", sizeof(unsigned long), 0);
        break;
    case 9:
        printf("%d,-9223372036854775808,9223372036854775807", sizeof(long long));
        break;
    case 10:
        printf("%d,0,18446744073709551615", sizeof(unsigned long long));
        break;
    }
    return 0;
}
