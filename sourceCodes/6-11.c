Vertex FindMinDist( MGraph Graph, int dist[], int collected[] )
{ /* ����δ����¼������dist��С�� */
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V=0; V<Graph->Nv; V++) {
		if ( collected[V]==false && dist[V]<MinDist) {
			/* ��Vδ����¼����dist[V]��С */
			MinDist = dist[V]; /* ������С���� */
			MinV = V; /* ���¶�Ӧ���� */
		}
	}
	if (MinDist < INFINITY) /* ���ҵ���Сdist */
		return MinV; /* ���ض�Ӧ�Ķ����±� */
	else return ERROR;  /* �������Ķ��㲻���ڣ����ش����� */
}

bool Dijkstra( MGraph Graph, int dist[], int path[], Vertex S )
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
	for ( V=0; V<Graph->Nv; V++ ) {
        dist[V] = Graph->G[S][V];
        if ( dist[V]<INFINITY )
           path[V] = S;
        else
           path[V] = -1;
        collected[V] = false;
    }
	/* �Ƚ�������뼯�� */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
        /* V = δ����¼������dist��С�� */
		V = FindMinDist( Graph, dist, collected );
		if ( V==ERROR ) /* ��������V������ */
			break;      /* �㷨���� */
		collected[V] = true;  /* ��¼V */
		for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
		    /* ��W��V���ڽӵ㲢��δ����¼ */
			if ( collected[W]==false && Graph->G[V][W]<INFINITY ) {
				if ( Graph->G[V][W]<0 ) /* ���и��� */
					return false; /* ������ȷ��������ش����� */
				/* ����¼Vʹ��dist[W]��С */
				if ( dist[V]+Graph->G[V][W] < dist[W] ) {
					dist[W] = dist[V]+Graph->G[V][W]; /* ����dist[W] */
					path[W] = V; /* ����S��W��·�� */
				}
			}
	} /* while����*/
	return true; /* �㷨ִ����ϣ�������ȷ��� */
}
