void SelectionSort ( int List[], int N )
{ /* ��N������List[0]...List[N-1]���зǵݼ����� */
	int i;
	for ( i=0; i<N; i++ ) {
	    /* ��List[i]��List[N-1]������СԪ��������λ�ø���MinPosition */
        MinPosition = ScanForMin( List, i, N-1 ); 

		/* ��δ���򲿷ֵ���СԪ�������򲿷ֵ����λ�� */
		Swap( List[i], List[MinPosition] );
	}
}
