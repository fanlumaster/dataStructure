/* ����9�׶���ʽ f(x)=1*x+2*(x^2)+...+9*(x^9) */
/* �ò�ͬ��������f(1.1)���ұȽ�����ʱ��                         */

#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;
#define MAXN 10  /* ����ʽ���������������ʽ����+1 */
#define MAXK 1e7 /* ���⺯������ظ����ô���*/

double f1( int n, double a[], double x )
{
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++ )
		p += (a[i] * pow(x, i));
	return p;
}

double f2( int n, double a[], double x )
{
	int i;
	double p = a[n];
	for ( i=n; i>0; i-- )
		p = a[i-1] + x*p;
	return p;
}

void run( double (*f)( int, double*, double ), double a[], int case_n )
{/* �˺������ڲ��Ա��⺯��(*f)������ʱ�䣬���Ҹ���case_n�����Ӧ�Ľ�� */
 /* case_n������ĺ�����ţ�1������f1��2������f2                   */
	int i;

	start = clock();
	for ( i=0; i<MAXK; i++ ) /* �ظ����ú����Ի�ó�ֶ��ʱ�Ӵ����*/
		(*f)(MAXN-1, a, 1.1);
	stop = clock();

	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks%d = %f\n", case_n, (double)(stop - start));
	printf("duration%d = %6.2e\n", case_n, duration);
}

int main ()
{
	int i;
	double a[MAXN]; /* �洢����ʽ��ϵ��*/

	/* Ϊ����Ķ���ʽϵ����ֵ����a[i]=i */
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i;

	run(f1, a, 1);
	run(f2, a, 2);

	return 0;
}
