double f( int n, double a[], double x )
{/* �������Ϊn��ϵ��Ϊa[0]...a[n]�Ķ���ʽ��x���ֵ */
	int i;
	double p = a[n];
	for ( i=n; i>0; i-- )
		p = a[i-1] + x * p;
	return p;
}
