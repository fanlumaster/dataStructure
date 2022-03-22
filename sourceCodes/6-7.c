/* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
/* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
bool IsEdge( MGraph Graph, Vertex V, Vertex W )
{
    return Graph->G[V][W]<INFINITY ? true : false;
}

/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void BFS ( MGraph Graph, Vertex S, void (*Visit)(Vertex) )
{   /* ��SΪ��������ڽӾ���洢��ͼGraph����BFS���� */
	Queue Q; 	
	Vertex V, W;

	Q = CreateQueue( MaxSize ); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
	/* ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д */
	Visit( S );
	Visited[S] = true; /* ���S�ѷ��� */
    AddQ(Q, S); /* S����� */
    
	while ( !IsEmpty(Q) ) {
		V = DeleteQ(Q);  /* ����V */
		for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
			/* ��W��V���ڽӵ㲢��δ���ʹ� */
			if ( !Visited[W] && IsEdge(Graph, V, W) ) {
                /* ���ʶ���W */
				Visit( W );
				Visited[W] = true; /* ���W�ѷ��� */
                AddQ(Q, W); /* W����� */
			}
	} /* while����*/
}
