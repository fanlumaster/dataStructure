int main()
{
	int N;    /* �˿����� */
	Queue Q;  /* �˿Ͷ��� */
	int i;
	ElementType X;

	scanf("%d", &N);    /* ����˿����� */
	Q = CreateQueue(N); /* �����յĹ˿Ͷ��� */

	for ( i=0; i<N; i++ ) { /* �˿��������� */
		scanf("%d %d", &X.T, &X.P);
		AddQ(Q, X);
	}

	/* ��ӡ��Nλ�˿�ƽ���ȴ�ʱ�� */
	printf("ƽ���ȴ�ʱ�� = %.1f ����\n", QueueingAtBank(Q, N));

	DestroyQueue(Q);	
	return 0;
}
