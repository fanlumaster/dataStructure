
void BubbleSort( ElementType A[], int N )
{ /* ð������ */
	int P, i;
	bool flag;

	for ( P=N-1; P>=0; P-- ) {
		flag = false; /* ��Ǹô�ѭ�����Ƿ������������ޣ���˵�������������� */
		for( i=0; i<P; i++ ) { /* һ��ð�� */
			/* ÿ��ѭ���ҳ�һ�����Ԫ�أ������������Ҷ� */
			if ( A[i] > A[i+1] ) {
				Swap( &A[i], &A[i+1] ); 
 				flag = true; /* ��ʶ�����˽��� */
			}
		}
		if ( flag==false ) break ; /*��ȫ���޽�����������ѭ��*/
	}
}
