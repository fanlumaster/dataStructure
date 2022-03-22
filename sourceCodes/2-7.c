ElementType Median( ElementType A[], int N )
{
	int i, j, MaxPosition;
	ElementType TmpA;

	for ( i=0; i<N-1; i++ ) {
		MaxPosition = i;
		for ( j=i+1; j<N; j++ ) /* 内循环找出最大值的下标MaxPosition */
			if ( A[j] > A[MaxPosition] )  MaxPosition = j;
		/* 下面将最大值与待排序序列的第一个元素A[i]交换 */
		TmpA=A[i];  A[i]=A[MaxPosition];  A[MaxPosition]=TmpA;
	} /* 排序结束 */

    /* 数组中下标为(N-1)/2位置的元素就是序列中第N/2个元素 */
	return A[(N-1)/2];  
}
