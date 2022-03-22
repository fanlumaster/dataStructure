int IterativeSum ( int List[], int N )
{ /* 循环求N个整数的和 */
    int i ; /* 执行1步 */
    int Sum = 0; /* 执行1步 */

    for ( i=0; i<N; i++ ) /* 共执行N+1步 */
       Sum += List[i] ;  /* 共执行N步   */

	return Sum;  /* 执行1步 */
}
