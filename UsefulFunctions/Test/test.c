#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("in.txt", "a");
    fprintf(fp, "Hello World!\n");
    fclose(fp);
    return 0;
}
