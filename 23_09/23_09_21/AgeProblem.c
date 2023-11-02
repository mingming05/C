#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int LittleA = a - b;
	int Grandma = a + c;
	printf("%d %d", LittleA, Grandma);
	return 0;
}