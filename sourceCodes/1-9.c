int IterativeSum ( int List[], int N )
{ /* ѭ����N�������ĺ� */
    int i ; /* ִ��1�� */
    int Sum = 0; /* ִ��1�� */

    for ( i=0; i<N; i++ ) /* ��ִ��N+1�� */
       Sum += List[i] ;  /* ��ִ��N��   */

	return Sum;  /* ִ��1�� */
}
