ElementType Median( ElementType S[], int N )
{   
	return FindKthLargest(S, (N+1)/2, 0, N-1);
}
