void DestroyTable( HashTable H )
{
	int i;
	Position P, Tmp;
    
    /* 释放每个链表的结点 */
	for( i=0; i<H->TableSize; i++ ) {
		P = H->Heads[i].Next;
		while( P ) {
			Tmp = P->Next;
			free( P );
			P = Tmp;
		}
	}
	free( H->Heads ); /* 释放头结点数组 */
	free( H );        /* 释放散列表结点 */
}
