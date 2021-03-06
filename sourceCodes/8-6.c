double QueueingAtBank( Queue Q, int N )
{   /* 根据顾客队列Q和人数N，返回顾客平均等待时间 */
	struct People Next; 
    int K;                   /* 营业窗口个数 */
	int TotalTime;           /* 全体顾客等待总时间 */
	int CurrentTime;         /* 当前时间，开门营业时为0 */
	int Window[MaxWindow];   /* 营业窗口需要处理事务的时间长度 */
	int WaitTime;            /* 相邻两次窗口空闲之间所等待的时间 */
	int WinAvail;            /* 空闲窗口的位置 */
	int i, j;

	int VIPWindow;  /* VIP窗口编号 */

	scanf("%d %d", &K, &VIPWindow);  /* 读入营业窗口个数和VIP窗口编号 */
	if ( N < K ) return 0;  /* 如果窗口比人多，则无须等待 */

    /*--------初始化--------*/
	for ( i=0; i<K; i++ )
		Window[i] = 0;
	TotalTime = 0;
	/*---------------------*/

	while ( !IsEmpty(Q) ) {

        /*--第1步：处理掉当前最短的事务，得到下一个空闲窗口--*/
		WinAvail = FindNextWindow( Window, K, &WaitTime );
		CurrentTime += WaitTime;

        /*-------------第2步：下一位顾客出列-------------*/
		if ((WinAvail == VIPWindow)&&(IsVipHere(Q, CurrentTime)))
			Next = DeleteVIP(Q); /* 如果VIP窗口空且有VIP在队伍中等 */
		else
			Next = DeleteQ(Q);
		if ( Next.T == EmptyQ ) break; /* 如果收到队列已空的信号，退出循环 */
		if ( CurrentTime >= Next.T ) /* 如果顾客已经到达等待 */
			TotalTime += (CurrentTime - Next.T); /* 累计等待时间 */
		else { /* 如果顾客还没到 */
			WaitTime = Next.T - CurrentTime; /* 空闲窗口等待顾客的时间 */
			for ( j=0; j<K; j++ ) { /* 刷新所有窗口至顾客到达的状态 */
				Window[j] -= WaitTime;
				if ( Window[j] < 0 )  Window[j] = 0;
			}
			CurrentTime = Next.T; /* 更新当前时间为顾客到达时间 */
		}
	
        /*---第3步：顾客Next到WinAvail窗口接受服务---*/
		Window[WinAvail] = Next.P;
	}
	return ((double)TotalTime/(double)N);
}
