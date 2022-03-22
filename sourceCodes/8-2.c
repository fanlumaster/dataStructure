int main()
{
	int N;    /* 顾客总数 */
	Queue Q;  /* 顾客队列 */
	int i;
	ElementType X;

	scanf("%d", &N);    /* 读入顾客人数 */
	Q = CreateQueue(N); /* 建立空的顾客队列 */

	for ( i=0; i<N; i++ ) { /* 顾客依次入列 */
		scanf("%d %d", &X.T, &X.P);
		AddQ(Q, X);
	}

	/* 打印出N位顾客平均等待时间 */
	printf("平均等待时间 = %.1f 分钟\n", QueueingAtBank(Q, N));

	DestroyQueue(Q);	
	return 0;
}
