#include <stdio.h>
#include <time.h>

clock_t  start, stop; /* clock_t��clock()�������صı������� */
double  duration;  /* ��¼���⺯������ʱ�䣬����Ϊ��λ */

int main ()
{	/* ���ڲ��Է�Χ�ڵ�׼������д��clock()����֮ǰ*/

	start = clock(); /* ��ʼ��ʱ */
	MyFunction(); 	 /* �ѱ��⺯���������ʹ��ʱ����������뱻�滻 */
	stop = clock();	 /* ֹͣ��ʱ */
	duration = ((double)(stop - start))/CLK_TCK; /* ��������ʱ�� */
	/* ע��CLK_TCK�ǻ���ʱ��ÿ�����ߵ�ʱ�Ӵ������ */
	/* ��ĳЩIDE��Ҳ���ܽ�CLOCKS_PER_SEC��         */

    /* �������ڲ��Է�Χ�Ĵ���д�ں��棬�������duration��ֵ */
	return 0;
}
