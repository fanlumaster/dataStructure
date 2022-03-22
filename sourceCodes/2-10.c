int Factorial( int N )
{
	if ( N == 0 )
		return 1;
	else
		return N * Factorial(N-1);
}
