void Show( HashTable H, double percent )
{
	int diffwordcount = 0;    /* ��ͬ�ĵ������� */
	int maxf = 0;             /* ���Ĵ�Ƶ */
	int *diffwords;           /* ÿ����Ƶ��Ӧ�Ĳ�ͬ�������� */
	int maxCollision = 0;     /* ����ͻ��������ʼ��Ϊ0 */
	int minCollision = 100;   /* ��С��ͻ��������ʼ��Ϊ100 */
	Position L;
	int i, j, k, lowerbound, count = 0;

	for( i=0; i<H->TableSize; i++ ) {
		/* ��ͬ�ĵ������� */
		diffwordcount += H->Heads[i].Count; /* ͷ���Countͳ�������� */
		/* ͳ��������С��ͻ���� */
		if( maxCollision<H->Heads[i].Count )
			maxCollision = H->Heads[i].Count;
		if( minCollision>H->Heads[i].Count )
			minCollision = H->Heads[i].Count;				
		/* �����Ĵ�Ƶ */
		L = H->Heads[i].Next; /* ��ÿ������ı�ͷ��ʼ */
		while( L ){ /* �������� */
			if( maxf<L->Count )  maxf = L->Count;
			L = L->Next;
		}
	} /* ����forѭ�� */
 
	printf("���� %d ����ͬ�ĵ��ʣ���Ƶ����� %d��\n", diffwordcount, maxf);
	printf("����ͻ������ %d, ��С��ͻ������ %d.\n", maxCollision, minCollision);			
            
	/* ��ÿ����Ƶ�ȼ�ӵ�еĲ�ͬ�������� */         
	/* �������Ĵ�Ƶ������һ���������� */
	diffwords = (int *)malloc((maxf+1)*sizeof(int));
	/* ͳ�ƴ�Ƶ��1��maxf�ĵ������� */
	for( i=0; i<=maxf; i++ ) 
		diffwords[i] = 0;   
	for( i=0; i<H->TableSize; i++ ) {
		L = H->Heads[i].Next; 
		while( L ){ /* �������� */
			diffwords[L->Count]++; /* �ô�Ƶ����һ������ */
			L = L->Next;
		}
	}
            
	/* ���ض��Ĵ�Ƶ��ʹ�ô��ڵ��ڸô�Ƶ�ĵ����ܺͳ��������ı��� */
	lowerbound = (int)(diffwordcount * percent);
	for ( i=maxf; i>=1 && count<lowerbound; i-- )
		count += diffwords[i];
	/* ����Ƶ�Ӵ�С������� */
	for( j=maxf; j>=i; j-- ) { /* ��ÿ����Ƶ */
		for( k=0; k<H->TableSize; k++ ) { /* ��������ɢ�б� */
			L = H->Heads[k].Next; 
			while( L ){
				if( j==L->Count ) /* ����һ�����ʵĴ�Ƶ�뵱ǰ��Ƶ��� */
					/* ����õ��ʼ���Ƶ */
					printf(" %-15s : %d \n", L->Data, L->Count);
				L = L->Next;
			}
		}
	}
	free( diffwords );
}

