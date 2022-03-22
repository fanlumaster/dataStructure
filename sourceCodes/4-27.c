SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
	for ( ; S[X]>=0; X=S[X] ) ;
	return X;
}
