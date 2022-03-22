LGraph CreateGraph( int VertexNum )
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V;
	LGraph Graph;
    
    Graph = (LGraph)malloc( sizeof(struct GNode) ); /* ����ͼ */
	Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* ��ʼ���ڽӱ�ͷָ�� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
   	for (V=0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
			
	return Graph; 
}
       
void InsertEdge( LGraph Graph, Edge E )
{
    PtrToAdjVNode NewNode;
    
    /* ����� <V1, V2> */
    /* ΪV2�����µ��ڽӵ� */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
	/* ��V2����V1�ı�ͷ */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
		
	/* ��������ͼ����Ҫ����� <V2, V1> */
    /* ΪV1�����µ��ڽӵ� */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
	/* ��V1����V2�ı�ͷ */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */ 
	
	scanf("%d", &(Graph->Ne));   /* ������� */
	if ( Graph->Ne != 0 ) { /* ����б� */ 
	    E = (Edge)malloc( sizeof(struct ENode) ); /* �����߽�� */ 
	    /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); 
		    /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            InsertEdge( Graph, E );
		}
	} 

	/* ������������ݵĻ����������� */
	for (V=0; V<Graph->Nv; V++) 
		scanf(" %c", &(Graph->G[V].Data));

	return Graph;
} 
