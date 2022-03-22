SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
	if ( S[X] < 0 ) /* 找到集合的根 */
		return X;
	else
		return S[X] = Find( S, S[X] ); /* 路径压缩 */
}
