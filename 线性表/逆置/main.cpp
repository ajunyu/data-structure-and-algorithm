/*
 * 算法实现带头结点单链表的就地逆置（不需要额外申请结点空间）
 */

// 伪代码
void reverseList(LinkList L)
{
	p = L->next;
	L->next = NULL;

	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
