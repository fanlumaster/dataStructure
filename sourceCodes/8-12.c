void PercDown( Edge ESet, int p, int N )
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�صı���������ESet[p]Ϊ�����Ӷѵ���Ϊ����Weight����С�� */
    int Parent, Child;
    struct ENode X;

    X = ESet[p]; /* ȡ��������ŵ�ֵ */
	for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
		Child = Parent * 2 + 1;
        if( (Child!=N-1) && (ESet[Child].Weight>ESet[Child+1].Weight) )
            Child++;  /* Childָ�������ӽ��Ľ�С�� */
        if( X.Weight <= ESet[Child].Weight ) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			ESet[Parent] = ESet[Child];
    }
    ESet[Parent] = X;
}

void InitializeESet( LGraph Graph, Edge ESet )
{ /* ��ͼ�ıߴ�������ESet�����ҳ�ʼ��Ϊ��С�� */
	Vertex V;
	PtrToAdjVNode W;
	int ECount;

	/* ��ͼ�ıߴ�������ESet */
	ECount = 0;
	for ( V=0; V<Graph->Nv; V++ )
		for ( W=Graph->G[V].FirstEdge; W; W=W->Next )
			if ( V < W->AdjV ) { /* �����ظ�¼������ͼ�ıߣ�ֻ��V1<V2�ı� */
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}
	/* ��ʼ��Ϊ��С�� */
	for ( ECount=Graph->Ne/2; ECount>=0; ECount-- )
		PercDown( ESet, ECount, Graph->Ne );
}

int GetEdge( Edge ESet, int CurrentSize )
{ /* ������ǰ�ѵĴ�СCurrentSize������ǰ��С��λ�õ����������� */

    /* ����С���뵱ǰ�ѵ����һ��λ�õı߽��� */
	Swap( &ESet[0], &ESet[CurrentSize-1]);
    /* ��ʣ�µı߼�����������С�� */
	PercDown( ESet, 0, CurrentSize-1 );

	return CurrentSize-1; /* ������С������λ�� */
}
