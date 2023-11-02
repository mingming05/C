#include <stdio.h>

int main()
{
	int a, b, c , i = 0;
	scanf("%d%d", &a, &b);
	for (c = 1 ; i < b; i++)
	{
		c = (c * a) % 7;
	}
	switch (c)
	{
		case 0:
		printf("Sunday\n");
		break;
		case 1:
		printf("Monday\n");
		break;
		case 2:
		printf("Tuesday\n");
		break;
		case 3:
		printf("Wednesday\n");
		break;
		case 4:
		printf("Thursday\n");
		break;
		case 5:
		printf("Friday\n");
		break;
		case 6:
		printf("Saturday\n");
		break;
	}
	return 0;
}