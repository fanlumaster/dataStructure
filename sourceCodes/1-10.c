int RecursiveSum ( int List[], int N )
{ /* 递归求N个整数的和 */
	if ( N )   /* 执行1步 */
		return (RecursiveSum(List, N-1)+List[N-1]); /* 执行X+2步 */
    return 0;  /* 执行1步 */
}
