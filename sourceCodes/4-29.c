SetName Find( SetType S, ElementType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
	if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
		return X;
	else
		return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
}
