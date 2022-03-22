void PercDown( Edge ESet, int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
  /* 将N个元素的边数组中以ESet[p]为根的子堆调整为关于Weight的最小堆 */
    int Parent, Child;
    struct ENode X;

    X = ESet[p]; /* 取出根结点存放的值 */
	for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
		Child = Parent * 2 + 1;
        if( (Child!=N-1) && (ESet[Child].Weight>ESet[Child+1].Weight) )
            Child++;  /* Child指向左右子结点的较小者 */
        if( X.Weight <= ESet[Child].Weight ) break; /* 找到了合适位置 */
		else  /* 下滤X */
			ESet[Parent] = ESet[Child];
    }
    ESet[Parent] = X;
}

void InitializeESet( LGraph Graph, Edge ESet )
{ /* 将图的边存入数组ESet，并且初始化为最小堆 */
	Vertex V;
	PtrToAdjVNode W;
	int ECount;

	/* 将图的边存入数组ESet */
	ECount = 0;
	for ( V=0; V<Graph->Nv; V++ )
		for ( W=Graph->G[V].FirstEdge; W; W=W->Next )
			if ( V < W->AdjV ) { /* 避免重复录入无向图的边，只收V1<V2的边 */
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}
	/* 初始化为最小堆 */
	for ( ECount=Graph->Ne/2; ECount>=0; ECount-- )
		PercDown( ESet, ECount, Graph->Ne );
}

int GetEdge( Edge ESet, int CurrentSize )
{ /* 给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆 */

    /* 将最小边与当前堆的最后一个位置的边交换 */
	Swap( &ESet[0], &ESet[CurrentSize-1]);
    /* 将剩下的边继续调整成最小堆 */
	PercDown( ESet, 0, CurrentSize-1 );

	return CurrentSize-1; /* 返回最小边所在位置 */
}
