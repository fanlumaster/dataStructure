int MaxSubseqSum2( int List[], int N )
{
	int i, j;
	int ThisSum, MaxSum = 0;

	for( i=0; i<N; i++ ) {     /* i���������λ�� */
		ThisSum = 0;  /* ThisSum�Ǵ�List[i]��List[j]�����к� */
		for( j=i; j<N; j++ ) { /* j�������Ҷ�λ�� */
			/*������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�1���*/
			ThisSum += List[j];
			if( ThisSum > MaxSum ) /* ����յõ���������к͸��� */
				MaxSum = ThisSum;   /* ����½�� */
		} /* jѭ������ */
    } /* iѭ������ */
	return MaxSum;
}
