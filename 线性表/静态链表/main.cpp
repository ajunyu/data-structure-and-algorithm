/*
* 数组的第一个和最后一个元素作为特殊元素处理，不存数据。
* 把未被使用的数组元素称为备用链表。
* 数组的第一个元素，即下标为0的元素的cur存放备用链表的第一个结点的下标。
* 数组中最后一个元素的cur则存放第一个有数值的元素的下标，相当于单链表头结点，整个链表为空时为0。
*/
#include <stdio.h>

#define MAXSIZE 7
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

typedef struct staticList
{
	ElemType dat;
	int cur;    //相当于单链表的next指针，存放该元素的后继在数组中的下标
}StaticLinkList[MAXSIZE];

int ListLength(StaticLinkList L);
void Free_SLL(StaticLinkList space, int k);

/*
* 将一维数组space中各分量链成一备用链表
* space[0].cur为头指针， "0"表示空指针
*/
Status InitList(StaticLinkList space)
{
	if (MAXSIZE <= 0)
		return ERROR;
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[i].cur = 0;
	return OK;
}

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
static int Malloc_SLL(StaticLinkList space)
{
	int index = space[0].cur;
	if (index != 0)
		space[0].cur = space[index].cur;
	return index;
}

/* 在L中第i个元素之前插入新的数据元素e */
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int length = ListLength(L);
	if (i < 1 || i > length + 1 || length == MAXSIZE - 2) {
		printf("Insert error!\n");
		return ERROR;
	}

	int newIndex = Malloc_SLL(L);
	if (newIndex == 0)
		return ERROR;

	L[newIndex].dat = e;
	int index = MAXSIZE - 1;
	for (int one = 1; one < i; one++)
		index = L[index].cur;
	L[newIndex].cur = L[index].cur;
	L[index].cur = newIndex;
	return OK;
}

/* 删除在L中第i个数据元素e */
Status ListDelete(StaticLinkList L, int i)
{
	int length = ListLength(L);
	if (i < 1 || i > length) {
		printf("Delete error!\n");
		return ERROR;
	}

	int index = MAXSIZE - 1;
	for (int one = 1; one < i; one++)
		index = L[index].cur;
	int del = L[index].cur;
	L[index].cur = L[del].cur;
	Free_SLL(L, del);
	return OK;
}

/* 将下标为k的空闲结点回收到备用链表 */
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList L)
{
	int len = 0;
	for (int index = MAXSIZE - 1; L[index].cur != 0; len++)
		index = L[index].cur;
	return len;
}

void PrintList(StaticLinkList L)
{
	for (int index = MAXSIZE - 1; L[index].cur != 0; printf("%d ", L[index].dat)) {
		index = L[index].cur;
	}
	printf("\n");
}

int main(void)
{
	StaticLinkList list;
	InitList(list);
	printf("Length : %d\n", ListLength(list));
	ListInsert(list, 1, 10);
	ListInsert(list, 1, 9);
	ListInsert(list, 1, 8);
	ListInsert(list, 3, 7);
	ListInsert(list, 1, 6);
	ListInsert(list, 1, 5);
	PrintList(list);
	printf("Length : %d\n", ListLength(list));
	ListDelete(list, 5);
	ListDelete(list, 5);
	ListInsert(list, 1, 5);
	ListInsert(list, 1, 5);
	PrintList(list);

	/*for(int i = 0; i < MAXSIZE; i++)
	printf("%d ", list[i].cur);
	printf("\n");
	for(int i = 0; i < MAXSIZE; i++)
	printf("%d ", list[i].dat);
	printf("\n");*/

	return 0;
}