Vertex FindMinDist( MGraph Graph, WeightType dist[] )
{ /* ����δ����¼������dist��С�� */
	Vertex MinV, V;
	WeightType MinDist = INFINITY;

	for (V=0; V<Graph->Nv; V++) {
		if ( dist[V]!=0 && dist[V]<MinDist) {
			/* ��Vδ����¼����dist[V]��С */
			MinDist = dist[V]; /* ������С���� */
			MinV = V; /* ���¶�Ӧ���� */
		}
	}
	if (MinDist < INFINITY) /* ���ҵ���Сdist */
		return MinV; /* ���ض�Ӧ�Ķ����±� */
	else return ERROR;  /* �������Ķ��㲻���ڣ�����-1��Ϊ��� */
}
