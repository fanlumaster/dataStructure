int Length( List L )
{
	Position p;
	int cnt = 0; /* ��ʼ�������� */

	p = L;  /* pָ���ĵ�һ����� */
	while ( p ) { 
		p = p->Next; 
		cnt++; /* ��ǰpָ����ǵ�cnt�����*/
	}   

	return cnt;
}
