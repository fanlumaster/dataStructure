/* 给定9阶多项式 f(x)=1*x+2*(x^2)+...+9*(x^9) */
/* 用不同方法计算f(1.1)并且比较运行时间                         */

#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;
#define MAXN 10  /* 多项式最大项数，即多项式阶数+1 */
#define MAXK 1e7 /* 被测函数最大重复调用次数*/

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
{/* 此函数用于测试被测函数(*f)的运行时间，并且根据case_n输出相应的结果 */
 /* case_n是输出的函数编号：1代表函数f1；2代表函数f2                   */
	int i;

	start = clock();
	for ( i=0; i<MAXK; i++ ) /* 重复调用函数以获得充分多的时钟打点数*/
		(*f)(MAXN-1, a, 1.1);
	stop = clock();

	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks%d = %f\n", case_n, (double)(stop - start));
	printf("duration%d = %6.2e\n", case_n, duration);
}

int main ()
{
	int i;
	double a[MAXN]; /* 存储多项式的系数*/

	/* 为本题的多项式系数赋值，即a[i]=i */
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i;

	run(f1, a, 1);
	run(f2, a, 2);

	return 0;
}
