/*
 * �㷨ʵ�ִ�ͷ��㵥����ľ͵����ã�����Ҫ����������ռ䣩
 */

// α����
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
