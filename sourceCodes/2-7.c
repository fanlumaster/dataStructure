ElementType Median( ElementType A[], int N )
{
	int i, j, MaxPosition;
	ElementType TmpA;

	for ( i=0; i<N-1; i++ ) {
		MaxPosition = i;
		for ( j=i+1; j<N; j++ ) /* ��ѭ���ҳ����ֵ���±�MaxPosition */
			if ( A[j] > A[MaxPosition] )  MaxPosition = j;
		/* ���潫���ֵ����������еĵ�һ��Ԫ��A[i]���� */
		TmpA=A[i];  A[i]=A[MaxPosition];  A[MaxPosition]=TmpA;
	} /* ������� */

    /* �������±�Ϊ(N-1)/2λ�õ�Ԫ�ؾ��������е�N/2��Ԫ�� */
	return A[(N-1)/2];  
}
