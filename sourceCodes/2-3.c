ElementType Max( ElementType S[], int N )
{ /* 求N个集合元素S[]中的最大值 */
	int i;
	ElementType CurMax = S[0];

	for ( i=1; i<N; i++ )
		if ( S[i] > CurMax ) /* 若A[i]比当前最大值还要大 */
			CurMax = S[i];   /* 则更新当前最大值 */
	return CurMax;
}
