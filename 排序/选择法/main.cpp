/*
������10��������ѡ����С��������
��νѡ�񷨾����Ƚ�10��������С������a[0]�Ի����ٽ�a[1]��a[9]����С������a[1]�Ի���ÿ�Ƚ�һ�֣��ҳ�һ��δ�������������С��һ�������Ƚ�9�֡�
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
