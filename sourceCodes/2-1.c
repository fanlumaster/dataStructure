ElementType Average( ElementType S[], int N )
{ /* 求N个集合元素S[]的平均值 */
	int i;
	ElementType Sum = 0;

    for ( i=0; i<N; i++ )
		Sum += S[i];  /* 将数组元素累加到Sum中 */

    return Sum/N;
}
