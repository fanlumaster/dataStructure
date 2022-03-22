void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}

void SimpleSelectionSort( ElementType A[], int N )
{ /* 简单选择排序 */
	int i, j, min;

	for ( i=0; i<N-1; i++ ) { /*寻找最小元素*/
		min = i;
		for ( j=i+1; j<N; j++ )
			if ( A[j] < A[min] )
				min = j; /* min记录最小元素位置 */
			/* 将第i个元素与最小元素交换 */
			Swap( &A[i], &A[min] );
	}
}
