int NextPrime( int N )
{ /* ���ش���N�Ҳ�����MAXTABLESIZE����С���� */
	int i, p = (N%2)? N+2 : N+1; /*�Ӵ���N����һ��������ʼ */

	while( p <= MAXTABLESIZE ) {
		for( i=(int)sqrt(p); i>2; i-- )
			if ( !(p%i) ) break; /* p�������� */
		if ( i==2 ) break; /* for����������˵��p������ */
		else  p += 2; /* ������̽��һ������ */
	}
	return p;
}

HashTable CreateTable( int TableSize )
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct TblNode));
	/* ��֤ɢ�б���󳤶������� */
	H->TableSize = NextPrime(TableSize);
	/* ������Ԫ���� */
	H->Cells = (Cell *)malloc(H->TableSize*sizeof(Cell));
	/* ��ʼ����Ԫ״̬Ϊ���յ�Ԫ�� */
	for( i=0; i<H->TableSize; i++ )
		H->Cells[i].Info = Empty;

	return H;
}
