#define ERROR -1 /* �����ǣ���ʾ������������ */

int Prim( MGraph Graph, LGraph MST )
{ /* ����С����������Ϊ�ڽӱ�洢��ͼMST��������СȨ�غ� */
	WeightType dist[MaxVertexNum], TotalWeight;
    Vertex parent[MaxVertexNum], V, W;
    int VCount;
	Edge E;
	
    /* ��ʼ����Ĭ�ϳ�ʼ���±���0 */
   	for (V=0; V<Graph->Nv; V++) {
        /* ���������V��Wû��ֱ�ӵıߣ���Graph->G[V][W]����ΪINFINITY */
   	    dist[V] = Graph->G[0][V];
   	    parent[V] = 0; /* ���Ҷ������ж���ĸ���㶼�ǳ�ʼ��0 */ 
    }
    TotalWeight = 0; /* ��ʼ��Ȩ�غ�     */
    VCount = 0;      /* ��ʼ����¼�Ķ����� */
    /* �����������ж��㵫û�бߵ�ͼ��ע�����ڽӱ�汾 */
    MST = CreateGraph(Graph->Nv);
    E = (Edge)malloc( sizeof(struct ENode) ); /* �����յı߽�� */
   	    
    /* ����ʼ��0��¼��MST */
	dist[0] = 0;
    VCount ++;
	parent[0] = -1; /* ��ǰ������0 */

	while (1) {
		V = FindMinDist( Graph, dist );
		/* V = δ����¼������dist��С�� */
		if ( V==ERROR ) /* ��������V������ */
			break;   /* �㷨���� */
			
		/* ��V����Ӧ�ı�<parent[V], V>��¼��MST */
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge( MST, E );
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;
		
		for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
			if ( dist[W]!=0 && Graph->G[V][W]<INFINITY ) {
			/* ��W��V���ڽӵ㲢��δ����¼ */
				if ( Graph->G[V][W] < dist[W] ) {
				/* ����¼Vʹ��dist[W]��С */
					dist[W] = Graph->G[V][W]; /* ����dist[W] */
					parent[W] = V; /* ������ */
				}
			}
	} /* while����*/
	if ( VCount < Graph->Nv ) /* MST���յĶ��㲻��|V|�� */
	   TotalWeight = ERROR;
	return TotalWeight;   /* �㷨ִ����ϣ�������СȨ�غͻ������ */
}
