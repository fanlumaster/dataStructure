void DestroyTable( HashTable H )
{
	int i;
	Position P, Tmp;
    
    /* �ͷ�ÿ������Ľ�� */
	for( i=0; i<H->TableSize; i++ ) {
		P = H->Heads[i].Next;
		while( P ) {
			Tmp = P->Next;
			free( P );
			P = Tmp;
		}
	}
	free( H->Heads ); /* �ͷ�ͷ������� */
	free( H );        /* �ͷ�ɢ�б��� */
}
