int MaxSubseqSum1( int List[], int N )
{
	int i, j, k;
	int ThisSum, MaxSum = 0;

	for ( i=0; i<N; i++ ) {     /* i���������λ�� */
		for ( j=i; j<N; j++ ) { /* j�������Ҷ�λ�� */
			ThisSum = 0;  /* ThisSum�Ǵ�List[i]��List[j]�����к� */
			for ( k=i; k<=j; k++ )
				ThisSum += List[k];
			if ( ThisSum > MaxSum ) /* ����յõ���������к͸��� */
				MaxSum = ThisSum;   /* ����½�� */
		} /* jѭ������ */
    } /* iѭ������ */
	return MaxSum;
}
