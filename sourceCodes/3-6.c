#define ERROR -1

ElementType FindKth( List L, int K )
{ /* ����ָ����λ��K������L����ӦԪ�� */
	Position p;
	int cnt = 1; /* λ���1��ʼ */

	p = L; /* pָ��L�ĵ�1����� */
	while ( p && cnt<K ) {
		p = p->Next;
		cnt++;  
	}
	if ( (cnt==K) && p )
		return p->Data; /* �ҵ���K�� */
	else
		return ERROR;   /* ���򷵻ش�����Ϣ */
}
