void PrintN ( int N )
{/* ��ӡ��1��N��ȫ�������� */
	if ( N > 0 ){
		PrintN( N-1 ); 
		printf("%d\n", N );
	}
} 
