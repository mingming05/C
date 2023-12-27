#include <stdio.h>
#include <math.h>
int getcount(int *a)
{
    int count = 0;
    int count1, count2, count3, count4 = 0, count5 = 0;
    count = a[5];              // 36占一个包裹
    count1 = a[4];             // 25占一个包裹
    count2 = a[3];             // 16占的包裹
    count3 = ceil(a[2] / 4.0); // 9占的包裹
    // 讨论25和1组合后的1剩余数量
    int empty; // 空余的
    empty = count1 * 36 - a[4] * 25;
    int residue; // 剩余容量
    residue = empty - a[0];
    if (residue >= 0)
    {
        a[0] = 0;
    }
    else
    {
        a[0] = abs(residue);
    }
    // 此时a[0]剩余a[0]个
    // 讨论16和4组合后的余量
    int empty1; // 空余的
    empty1 = count2 * 36 - a[3] * 16;
    int residue1; // 剩余容量
    residue1 = empty1 - 4 * a[1];
    if (residue >= 0)
    {
        a[1] = 0;
    } // 如果还有剩余容量则a[1]装满
    else
    {
        a[1] = abs(residue) / 4; // 剩余的a[1]数量
    }
    if (a[0] + a[1] != 0)
    {
        int empty2; // 空余的
        empty2 = count3 * 36 - a[2] * 9;
        int residue2; // 剩余容量
        residue2 = empty2 - 4 * a[1];
        if (residue2 >= 0)
        {
            a[1] = 0;
            residue2 = residue2 - a[0];
            if (residue2 >= 0)
            {
                a[0] = 0;
            }
            else
            {
                a[0] = abs(residue2);
                count5 = ceil(a[0] / 36.0);
                a[0] = 0; // 如果a[0]有多的就再分配一个包裹
            }
        }
        else
        {
            a[1] = abs(residue) / 4;
        }

    } // 如果a[0]和a[1]有余量则放到9占的包裹的剩余之中
    if (a[0] + a[1] != 0)
    {
        count4 = ceil(a[1] / 9.0); // 为多余的4分配背包
        a[1] = 0;
        residue = count4 * 36 - 4 * a[1];
        if (residue >= 0)
        {
            a[0] = 0;
        }
        else
        {
            a[0] = abs(residue);
            count5 = ceil(a[0] / 36.0);
            a[0] = 0;
        }
    }

    if (a[0] + a[1] == 0)
    {
        /*printf("count=%d\n", count);
        printf("count1=%d\n", count1);
        printf("count2=%d\n", count2);
        printf("count3=%d\n", count3);
        printf("count4=%d\n", count4);
        printf("count5=%d\n", count5);
        */
        return count + count1 + count2 + count3 + count4 + count5;
    } // 已经全部分配完，可以返回了
}

int main()
{
    int a[6];
    int n;
    int count = 0;
    int b[1000] = {0};
    while (1)
    {
        for (int i = 0; i < 6; i++)
        {
            scanf_s("%d", &a[i]);
        }
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0)
        {
            break;
        }
        b[count] = getcount(a);
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", b[i]);
    }
    return 0;
}