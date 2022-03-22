double f( int n, double a[], double x )
{/* 计算阶数为n，系数为a[0]...a[n]的多项式在x点的值 */
	int i;
	double p = a[n];
	for ( i=n; i>0; i-- )
		p = a[i-1] + x * p;
	return p;
}
