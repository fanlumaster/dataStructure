SetName Find( SetType S, ElementType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
	for ( ; S[X]>=0; X=S[X] ) ;
	return X;
}
