ElementType Max( ElementType S[], int N )
{ /* ��N������Ԫ��S[]�е����ֵ */
	int i;
	ElementType CurMax = S[0];

	for ( i=1; i<N; i++ )
		if ( S[i] > CurMax ) /* ��A[i]�ȵ�ǰ���ֵ��Ҫ�� */
			CurMax = S[i];   /* ����µ�ǰ���ֵ */
	return CurMax;
}
