/*
例：用起泡法对10个数排序（从小到大）。
思路：将相邻两个数比较，将小的放前头，大的放后面，经过第一趟，最大的数沉底，然后进行第二趟比较，得到次大的数，如此进行。
*/

#include <stdio.h>
void main()
{
	int a[10], t;
	printf("input 10 numbers:\n");
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	/* 10个数进行9次比较 */
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9 - i; j++)
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	printf("result:\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
}

/*
运行情况如下：
Input 10 numbers:
1 0 4 8 12 65 - 76 100 - 45 123
The second numbers :
-76 - 45 0 1 4 8 12 65 100 123
*/
