void Swap( ElementType *X, ElementType *Y )
{ /* ����X��Y����Ԫ�� */
	ElementType tmp;
    tmp = *X; *X = *Y; *Y = tmp;
} 

ElementType FindKthLargest ( ElementType S[], int K, int Left, int Right )
{  /* ��S[Left]...S[Right]���ҵ�K��Ԫ�� */
	ElementType e = S[Left]; /* ��ȡ��Ԫ��Ϊ��׼ */
	int L = Left, R = Right;

	while (1) { /* �������бȻ�׼����Ƶ���׼��ߣ�С���Ƶ��ұ� */
		while ( (Left<=Right)&&(e <= S[Left]) )  Left++;
		while ( (Left<Right)&&(e > S[Right]) )  Right--;
        if ( Left < Right )
		    Swap ( &S[Left], &S[Right] ) ;
		else  break;
	}
    Swap ( &S[Left-1], &S[L] ); /* ����׼����������֮�� */
	if ( (Left-L-1) >= K ) /* (Left-L-1)�����˼���S1�Ĵ�С */
		return FindKthLargest(S, K, L, Left-2); /* �ڼ���S1���� */
	else if ( (Left-L-1) < K-1 ) 
		return FindKthLargest(S, K-(Left-L-1)-1, Left, R); /* �ڼ���S2���� */
	else 
		return e;/* �ҵ������� */
}
