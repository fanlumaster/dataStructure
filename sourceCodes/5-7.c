HashTable CreateTable( int TableSize )
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct TblNode));
	/* ��֤ɢ�б���󳤶������������������5.3 */
	H->TableSize = NextPrime(TableSize);

    /* ���·�������ͷ������� */
    H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
    /* ��ʼ����ͷ��� */
    for( i=0; i<H->TableSize; i++ ) {
         H->Heads[i].Data[0] = '\0';
         H->Heads[i].Next = NULL;
    }

    return H;
}
