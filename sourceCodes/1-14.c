int MaxSubseqSum4( int List[], int N )
{
	int i;
	int ThisSum, MaxSum;

	ThisSum = MaxSum = 0;
	for ( i=0; i<N; i++ ) {
		ThisSum += List[i]; /* �����ۼ� */
		if ( ThisSum > MaxSum )
			MaxSum = ThisSum; /* ���ָ��������µ�ǰ��� */
		else if ( ThisSum < 0 ) /* �����ǰ���к�Ϊ�� */
			ThisSum = 0; /* �򲻿���ʹ����Ĳ��ֺ���������֮ */
	} 
	return MaxSum;
}
