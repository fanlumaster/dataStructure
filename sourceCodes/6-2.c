/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;

MGraph CreateGraph( int VertexNum )
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V, W;
	MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->Nv = VertexNum;
    Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V=0; V<Graph->Nv; V++)
		for (W=0; W<Graph->Nv; W++)  
			Graph->G[V][W] = INFINITY;
			
	return Graph; 
}
       
void InsertEdge( MGraph Graph, Edge E )
{
     /* ����� <V1, V2> */
     Graph->G[E->V1][E->V2] = E->Weight;    
     /* ��������ͼ����Ҫ�����<V2, V1> */
     Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */ 
	
	scanf("%d", &(Graph->Ne));   /* ������� */
	if ( Graph->Ne != 0 ) { /* ����б� */ 
	    E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */ 
	    /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); 
		    /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            InsertEdge( Graph, E );
        }
	} 

	/* ������������ݵĻ����������� */
	for (V=0; V<Graph->Nv; V++) 
		scanf(" %c", &(Graph->Data[V]));

	return Graph;
} 
