ElementType Average( ElementType S[], int N )
{ /* ��N������Ԫ��S[]��ƽ��ֵ */
	int i;
	ElementType Sum = 0;

    for ( i=0; i<N; i++ )
		Sum += S[i];  /* ������Ԫ���ۼӵ�Sum�� */

    return Sum/N;
}
