void PercDown( ElementType A[], int p, int N )
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    ElementType X;

    X = A[p]; /* ȡ��������ŵ�ֵ */
	for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
		Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= A[Child] ) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			A[Parent] = A[Child];
    }
    A[Parent] = X;
}

void HeapSort( ElementType A[], int N ) 
{ /* ������ */
     int i;
      
     for ( i=N/2-1; i>=0; i-- )/* �������� */
         PercDown( A, i, N );
     
     for ( i=N-1; i>0; i-- ) {
		 /* ɾ�����Ѷ� */
         Swap( &A[0], &A[i] ); /* ������7.1 */
         PercDown( A, 0, i );
     }
}
