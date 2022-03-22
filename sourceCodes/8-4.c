int FindNextWindow( int W[], int K, int *WaitTime )
{   /* ����K������W[]��״̬��������һ�����д��ڵ�λ�� */
	/* �Լ����������δ��ڿ���֮�����ȴ���ʱ��WaitTime */
	int WinAvail;  /* ��һ�����д��ڵ�λ�� */
	int MinW = MaxProc+1; /* ���������ʱ�䣬��ʼ��Ϊ�������ֵ */
	int i;

	for ( i=0; i<K; i++ )  /* ɨ��ÿ�����ڣ��ҵ�������� */
		if ( W[i] < MinW ) {
			MinW = W[i];  WinAvail = i;
		}
	*WaitTime = MinW; /* ���������ʱ��������οմ���ĵȴ�ʱ�� */
	for ( i=0; i<K; i++ ) /* ˢ�����д��ڵ�������״̬ */
		W[i] -= MinW;

	return WinAvail; /* ������һ�����д��ڵ�λ�� */
}
