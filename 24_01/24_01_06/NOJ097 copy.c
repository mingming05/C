#include <stdio.h>
 
int arr[1005] = {0};
 
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	{
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; ++j)
			if (arr[i] == arr[j]) {
				++cnt;
				break;
			}
	}
	printf("%d\n", cnt);
}
 
//10 1 10 20 1 25 1 10 30 25 1