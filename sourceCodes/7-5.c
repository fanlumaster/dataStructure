
void BubbleSort( ElementType A[], int N )
{ /* 冒泡排序 */
	int P, i;
	bool flag;

	for ( P=N-1; P>=0; P-- ) {
		flag = false; /* 标记该次循环中是否发生交换，若无，则说明整个序列有序 */
		for( i=0; i<P; i++ ) { /* 一趟冒泡 */
			/* 每次循环找出一个最大元素，被交换到最右端 */
			if ( A[i] > A[i+1] ) {
				Swap( &A[i], &A[i+1] ); 
 				flag = true; /* 标识发生了交换 */
			}
		}
		if ( flag==false ) break ; /*若全程无交换，则跳出循环*/
	}
}
