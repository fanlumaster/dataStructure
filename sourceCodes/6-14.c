bool TopSort( LGraph Graph, Vertex TopOrder[] )
{ /* ��Graph������������,  TopOrder[]˳��洢�����Ķ����±� */
    int Indegree[MaxVertexNum], cnt;
    Vertex V;
    PtrToAdjVNode W;
   	Queue Q = CreateQueue( Graph->Nv );
 
    /* ��ʼ��Indegree[] */
    for (V=0; V<Graph->Nv; V++)
        Indegree[V] = 0;
        
    /* ����ͼ���õ�Indegree[] */
    for (V=0; V<Graph->Nv; V++)
        for (W=Graph->G[V].FirstEdge; W; W=W->Next)
            Indegree[W->AdjV]++; /* �������<V, W->AdjV>�ۼ��յ����� */
            
    /* ���������Ϊ0�Ķ������� */
    for (V=0; V<Graph->Nv; V++)
        if ( Indegree[V]==0 )
            AddQ(Q, V);
            
    /* ��������������� */ 
    cnt = 0; 
	while( !IsEmpty(Q) ){
		V = DeleteQ(Q); /* ����һ�����Ϊ0�Ķ��� */
		TopOrder[cnt++] = V; /* ��֮��Ϊ������е���һ��Ԫ�� */
		/* ��V��ÿ���ڽӵ�W->AdjV */
		for ( W=Graph->G[V].FirstEdge; W; W=W->Next )
			if ( --Indegree[W->AdjV] == 0 )/* ��ɾ��Vʹ��W->AdjV���Ϊ0 */
				AddQ(Q, W->AdjV); /* ��ö������� */ 
	} /* while����*/
    
    if ( cnt != Graph->Nv )
        return false; /* ˵��ͼ���л�·, ���ز��ɹ���־ */ 
    else
        return true;
} 
