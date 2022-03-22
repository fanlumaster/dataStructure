double QueueingAtBank( Queue Q, int N )
{   /* ���ݹ˿Ͷ���Q������N�����ع˿�ƽ���ȴ�ʱ�� */
	struct People Next;     /* ��һλ�˿� */
    int K;                  /* Ӫҵ���ڸ��� */
	int TotalTime;          /* ȫ��˿͵ȴ���ʱ�� */
	int CurrentTime;        /* ��ǰʱ�䣬����ӪҵʱΪ0 */
	int Window[MaxWindow];  /* Ӫҵ������Ҫ���������ʱ�䳤�� */
	int WaitTime;           /* �������δ��ڿ���֮�����ȴ���ʱ�� */
	int WinAvail;           /* ���д��ڵ�λ�� */
	int i, j;

	scanf("%d", &K);  /* ����Ӫҵ���ڸ��� */
	if ( N < K ) return 0;  /* ������ڱ��˶࣬������ȴ� */

    /*--------��ʼ��--------*/
	for ( i=0; i<K; i++ )
		Window[i] = 0;
	TotalTime = 0;
	/*---------------------*/

	while ( !IsEmpty(Q) ) { /* �����зǿ�ʱ���������� */

        /*--��1�����������ǰ��̵����񣬵õ���һ�����д���--*/
		WinAvail = FindNextWindow( Window, K, &WaitTime );
		CurrentTime += WaitTime;

        /*-------------��2������һλ�˿ͳ���-------------*/
		Next = DeleteQ(Q);
		if ( CurrentTime >= Next.T ) /* ����˿��Ѿ�����ȴ� */
			TotalTime += (CurrentTime - Next.T); /* �ۼƵȴ�ʱ�� */
		else { /* ����˿ͻ�û�� */
			WaitTime = Next.T - CurrentTime; /* ���д��ڵȴ��˿͵�ʱ�� */
			for ( j=0; j<K; j++ ) { /* ˢ�����д������˿͵����״̬ */
				Window[j] -= WaitTime;
				if ( Window[j] < 0 )  Window[j] = 0;
			}
			CurrentTime = Next.T; /* ���µ�ǰʱ��Ϊ�˿͵���ʱ�� */
		}

        /*---��3�����˿�Next��WinAvail���ڽ��ܷ���---*/
		Window[WinAvail] = Next.P;
	}

    /* ����ÿλ�˿͵�ƽ���ȴ�ʱ�� */
	return ((double)TotalTime/(double)N);
}
