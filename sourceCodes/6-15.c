#define SIX 6
int Visited[MaxVertexNum];

void InitializeVisited( int Nv )
{
	Vertex V;
	for ( V=0; V<Nv; V++ )
		Visited[V] = false;
}

int SDS_BFS( LGraph Graph, Vertex S )
{ /* 以S为出发点对Graph进行6层BFS搜索 */
	Queue Q;
	Vertex V, Last, Tail;
	PtrToAdjVNode W;
	int Count, Level;

	Q = CreateQueue( MaxSize ); /* 创建空队列, MaxSize为外部定义的常数 */
	Visited[S] = true; /* 标记S已访问 */
	Count = 1;         /* 统计人数从1开始 */
	Level = 0;         /* 起始点定义为第0层 */
	Last = S;          /* 该层只有S一个顶点，是该层被访问的最后一个顶点 */
    AddQ (Q, S);       /* S入队列 */
    
	while ( !IsEmpty(Q) ) {
		V = DeleteQ(Q);  /* 弹出V */
		for( W=Graph->G[V].FirstEdge; W; W=W->Next ) {/* 对V的每个邻接点W->AdjV */
			if ( !Visited[W->AdjV] ) {   /* 若W->AdjV未被访问 */
				Visited[W->AdjV] = true; /* 标记W->AdjV已访问 */
				Count++;                 /* 统计人数 */
				Tail = W->AdjV;          /* 当前层尾 */
                AddQ (Q, W->AdjV);       /* W->AdjV入队列 */
			}
		}
		if ( V==Last ) { /* 如果上一层的最后一个顶点弹出了 */
			Level++;     /* 层数递增 */
			Last = Tail; /* 更新当前层尾为该层被访问的最后一个顶点 */
		}
		if ( Level==SIX ) break; /* 6层遍历结束，退出搜索 */
	} /* while结束*/
	DestroyQueue( Q );
	return Count; /* 返回统计数据 */
}

void Six_Degrees_of_Separation( LGraph Graph ) 
{ /* 用邻接表存储图，对每个顶点检验六度空间理论 */
	Vertex V;
	int count;

	for( V=0; V<Graph->Nv; V++ ) { /* 对图中的每个顶点V */
		InitializeVisited( Graph->Nv );
		count = SDS_BFS( Graph, V );
		printf("顶点%d的六度覆盖比例 = %.2f%%\n", V, 100.0*(double)count/(double)Graph->Nv);
	}
}
