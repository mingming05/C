//求最大公约数方法
int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
//小数位数
int digit(int n)
{
    int count = 1;
    while (n / 10 != 0)
    {
        count += 1;
        n /= 10;
    }
    return count;
}
//格式化输出冰雹序列(考拉斯猜想)
void printCollatz(int n)
{
    printf("%d ", n);
    while (n > 2)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            printf("%d ", n);
        }
        else
        {
            n = 3 * n + 1;
            printf("%d ", n);
        }
    }
    printf("1");
}
//判断是否为素数
int isPrime(int n)
{
    if(n==2||n==3)
    {
        return 1;
    }
    int maximum = sqrt(n);
    for (int i = 2; i <= maximum; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
//格式化输出竖式乘法
void formatting(int m, int n)
{
    int digitvalue = digit(n * m);
    int digitm = digit(m);
    int digitn = digit(n);
    int arrn[digitn];
    int ncopy = n;
    int digiteach[digitn]; // 等于n的每一位与m乘积的位数

    for (int i = 0; i < digitn; i++)
    {
        arrn[i] = ncopy % 10;
        ncopy /= 10;
        digiteach[i] = digit(arrn[i] * m);
    }

    for (int i = 0; i < digitvalue - digitm + 1; i++)
    {
        printf(" ");
    }
    printf("%d\nx", m);
    for (int i = 0; i < digitvalue - digitn; i++)
    {
        printf(" ");
    }
    printf("%d\n", n);
    for (int i = 0; i <= digitvalue; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < digitn-1; i++)
    {
        for (int j = 0; j < digitvalue - digiteach[i] + 1 - i; j++)
        {
            printf(" ");
        }
        printf("%d", arrn[i] * m);
        for (int k = 0; k < i; k++)
        {
            printf(" ");
        }
        printf("\n");
    }
    printf("+%d", arrn[digitn - 1] * m);
    for(int i = 0; i < digitn - 1; i++)
    {
        printf(" ");
    }
    printf("\n");
    for (int i = 0; i <= digitvalue; i++)
    {
        printf("-");
    }
    printf("\n ");
    printf("%d", m * n);
    return;
}
//判断整数各位数字从高位到低位递减
int isDecreasing(int n)
{
    int digitvalue = digit(n);
    int arr[digitvalue];
    int ncache = n;
    for (int i = 0; i < digitvalue; i++)
    {
        arr[i] = ncache % 10;
        ncache /= 10;
    }
    for (int i = 0; i < digitvalue - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
//约分分子与分母
void simplify(int *numerator, int *denominator)
{
    int a = *numerator, b = *denominator;
    int gcdvalue = gcd(a, b);
    a /= gcdvalue;
    b /= gcdvalue;
    *numerator = a;
    *denominator = b;
}
//判断小数位数
int numofdec(double dec)
{
    int count = 0;
    double integer = floor(dec);
    while (dec - integer != 0.0)
    {
        count += 1;
        dec *= 10.0;
        integer = floor(dec);
    }
    return count;
}
//冒泡排序算法
int Bubble(int carriage[], int n)
{
    int sum = 0, check, a;
    do
    {
        check = 0;
        a = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (carriage[i] > carriage[i + 1])
            {
                int cache = carriage[i];
                carriage[i] = carriage[i + 1];
                carriage[i + 1] = cache;
                sum += 1;
                a += 1;
            }
        }
        if (a == 0)
        {
            check = 0;
        }
        else
        {
            check = 1;
        }

    } while (check);
    return sum;
}
