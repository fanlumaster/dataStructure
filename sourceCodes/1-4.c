double f( int n, double a[], double x )
{/* 计算阶数为n，系数为a[0]...a[n]的多项式在x点的值 */
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++ )
		p += a[i] * pow(x, i);
	return p;
}
