void Swap( ElementType *X, ElementType *Y )
{ /* 交换X和Y两个元素 */
	ElementType tmp;
    tmp = *X; *X = *Y; *Y = tmp;
} 

ElementType FindKthLargest ( ElementType S[], int K, int Left, int Right )
{  /* 在S[Left]...S[Right]中找第K大元素 */
	ElementType e = S[Left]; /* 简单取首元素为基准 */
	int L = Left, R = Right;

	while (1) { /* 将序列中比基准大的移到基准左边，小的移到右边 */
		while ( (Left<=Right)&&(e <= S[Left]) )  Left++;
		while ( (Left<Right)&&(e > S[Right]) )  Right--;
        if ( Left < Right )
		    Swap ( &S[Left], &S[Right] ) ;
		else  break;
	}
    Swap ( &S[Left-1], &S[L] ); /* 将基准换到两集合之间 */
	if ( (Left-L-1) >= K ) /* (Left-L-1)代表了集合S1的大小 */
		return FindKthLargest(S, K, L, Left-2); /* 在集合S1中找 */
	else if ( (Left-L-1) < K-1 ) 
		return FindKthLargest(S, K-(Left-L-1)-1, Left, R); /* 在集合S2中找 */
	else 
		return e;/* 找到，返回 */
}
