/* ��ʹ��ѭ���ݹ��ӡ0-999 */
#include <stdio.h>

#define PRINT(x) x; x; x; x; x; x; x; x; x; x;

int main(void)
{
	int n = 0;
	PRINT(PRINT(PRINT(printf("%d ", n++);); printf("\n");););
	return 0;
}
