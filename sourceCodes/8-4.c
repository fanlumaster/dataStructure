int FindNextWindow( int W[], int K, int *WaitTime )
{   /* 给定K个窗口W[]的状态，返回下一个空闲窗口的位置 */
	/* 以及在相邻两次窗口空闲之间所等待的时间WaitTime */
	int WinAvail;  /* 下一个空闲窗口的位置 */
	int MinW = MaxProc+1; /* 最短事务处理时间，初始化为超过最大值 */
	int i;

	for ( i=0; i<K; i++ )  /* 扫描每个窗口，找到最短事务 */
		if ( W[i] < MinW ) {
			MinW = W[i];  WinAvail = i;
		}
	*WaitTime = MinW; /* 最短事务处理时间就是两次空窗间的等待时间 */
	for ( i=0; i<K; i++ ) /* 刷新所有窗口的事务处理状态 */
		W[i] -= MinW;

	return WinAvail; /* 返回下一个空闲窗口的位置 */
}
