void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}

void SimpleSelectionSort( ElementType A[], int N )
{ /* ��ѡ������ */
	int i, j, min;

	for ( i=0; i<N-1; i++ ) { /*Ѱ����СԪ��*/
		min = i;
		for ( j=i+1; j<N; j++ )
			if ( A[j] < A[min] )
				min = j; /* min��¼��СԪ��λ�� */
			/* ����i��Ԫ������СԪ�ؽ��� */
			Swap( &A[i], &A[min] );
	}
}
