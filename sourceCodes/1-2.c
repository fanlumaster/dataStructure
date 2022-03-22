void PrintN ( int N )
{/* 打印从1到N的全部正整数 */
	if ( N > 0 ){
		PrintN( N-1 ); 
		printf("%d\n", N );
	}
} 
