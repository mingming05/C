// #include <stdio.h>

/*int main()
{
    long long unsigned n = 1, k;
    scanf("%d", &k);
    long long unsigned facmod = 1;
    while (facmod % k != 0)
    {
        n++;
        facmod = facmod * n % k;
        printf("%llu\n", facmod);
    }
    printf("%llu", n);

    return 0;
}
*/

#include <iostream>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define pb push_back
const int INF = 1e21;
typedef long long ll;
const int maxn = 1e4 + 7;
long long int t, p;
bool isPrime(int p)
{
    if (p == 1)
        return false;
    for (int i = 2; i * i <= p; i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    cin >> p;
    if (p == 1 || isPrime(p))
    {
        cout << p;
    }
    else
    {
        for (int i = 2;; i++)
        {
            if (gcd(i, p) != 1)
            {
                p /= gcd(i, p);
                if (p == 1)
                {
                    cout << i;
                    break;
                }
                if (i < p && isPrime(p))
                {
                    cout << p;
                    break;
                }
            }
        }
    }
    return 0;
}