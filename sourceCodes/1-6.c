#include <stdio.h>
#include <time.h>

clock_t  start, stop; /* clock_t是clock()函数返回的变量类型 */
double  duration;  /* 记录被测函数运行时间，以秒为单位 */

int main ()
{	/* 不在测试范围内的准备工作写在clock()调用之前*/

	start = clock(); /* 开始计时 */
	MyFunction(); 	 /* 把被测函数加在这里，使用时这个函数必须被替换 */
	stop = clock();	 /* 停止计时 */
	duration = ((double)(stop - start))/CLK_TCK; /* 计算运行时间 */
	/* 注意CLK_TCK是机器时钟每秒所走的时钟打点数， */
	/* 在某些IDE下也可能叫CLOCKS_PER_SEC。         */

    /* 其他不在测试范围的处理写在后面，例如输出duration的值 */
	return 0;
}
