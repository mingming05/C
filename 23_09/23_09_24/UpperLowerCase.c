#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char drug_name[n][21];
    for (int row = 0; row < n; row++)
    {
        scanf("%20s",&drug_name[row]);
        drug_name[row][0] = toupper(drug_name[row][0]);
        for (int column = 1; column < 20; column++)
        {
            drug_name[row][column] = tolower(drug_name[row][column]);
        }
    }
    for (int row = 0; row < n; row++)
    {
        printf("%s\n",drug_name[row]);
    }
    return 0;
}