double f( int n, double a[], double x )
{/* �������Ϊn��ϵ��Ϊa[0]...a[n]�Ķ���ʽ��x���ֵ */
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++ )
		p += a[i] * pow(x, i);
	return p;
}
