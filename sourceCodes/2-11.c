void Move( int n, int start, int goal, int temp )
{
    if ( n > 1 ) {
		Move( n-1, start, temp, goal );
		printf("Move disk %d from %d to %d.\n", n, start, goal);
		Move( n-1, temp, goal, start );
	}
	/* else ��n==1ʱ����Ҫ���κ��� */
}
