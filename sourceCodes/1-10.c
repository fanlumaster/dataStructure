int RecursiveSum ( int List[], int N )
{ /* �ݹ���N�������ĺ� */
	if ( N )   /* ִ��1�� */
		return (RecursiveSum(List, N-1)+List[N-1]); /* ִ��X+2�� */
    return 0;  /* ִ��1�� */
}
