#include <stdio.h>

/* "void PrintN ( int N )"可使用"1-1.c"或"1-2.c" */
void PrintN ( int N );

int main ()
{/* 读入整数N，并调用PrintN函数 */
	int N;
	scanf("%d", &N);
	PrintN( N );
	return 0;
}

