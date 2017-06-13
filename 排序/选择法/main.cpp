/*
例：对10个整数按选择法由小到大排序。
所谓选择法就是先将10个数中最小的数与a[0]对换，再将a[1]到a[9]中最小的数与a[1]对换，每比较一轮，找出一个未经排序的数中最小的一个，共比较9轮。
*/

#include <stdio.h>
void main()
{
	int a[10], t;
	printf("input 10 numbers:\n");
	for (int i = 0; i<10; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j<9; j++)
		for (int i = j + 1; i<10; i++)
			if (a[i]<a[j]) {
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
	printf("result:\n");
	for (int i = 0; i<10; i++)
		printf("%d ", a[i]);
}
