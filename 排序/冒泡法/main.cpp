/*
���������ݷ���10�������򣨴�С���󣩡�
˼·���������������Ƚϣ���С�ķ�ǰͷ����ķź��棬������һ�ˣ����������ף�Ȼ����еڶ��˱Ƚϣ��õ��δ��������˽��С�
*/

#include"stdio.h"
void main()
{
	int a[10], t;
	printf("input 10 numbers:\n");
	for (int i = 0; i<10; i++)
		scanf("%d", &a[i]);
	/* 10��������9�αȽ� */
	for (int i = 0; i<9; i++)
		for (int j = 0; j<9 - i; j++)
			if (a[j]>a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	printf("result:\n");
	for (int i = 0; i<10; i++)
		printf("%d ", a[i]);
}

/*
����������£�
Input 10 numbers:
1 0 4 8 12 65 - 76 100 - 45 123
The second numbers :
-76 - 45 0 1 4 8 12 65 100 123
*/
