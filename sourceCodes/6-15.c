#define SIX 6
int Visited[MaxVertexNum];

void InitializeVisited( int Nv )
{
	Vertex V;
	for ( V=0; V<Nv; V++ )
		Visited[V] = false;
}

int SDS_BFS( LGraph Graph, Vertex S )
{ /* ��SΪ�������Graph����6��BFS���� */
	Queue Q;
	Vertex V, Last, Tail;
	PtrToAdjVNode W;
	int Count, Level;

	Q = CreateQueue( MaxSize ); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
	Visited[S] = true; /* ���S�ѷ��� */
	Count = 1;         /* ͳ��������1��ʼ */
	Level = 0;         /* ��ʼ�㶨��Ϊ��0�� */
	Last = S;          /* �ò�ֻ��Sһ�����㣬�Ǹò㱻���ʵ����һ������ */
    AddQ (Q, S);       /* S����� */
    
	while ( !IsEmpty(Q) ) {
		V = DeleteQ(Q);  /* ����V */
		for( W=Graph->G[V].FirstEdge; W; W=W->Next ) {/* ��V��ÿ���ڽӵ�W->AdjV */
			if ( !Visited[W->AdjV] ) {   /* ��W->AdjVδ������ */
				Visited[W->AdjV] = true; /* ���W->AdjV�ѷ��� */
				Count++;                 /* ͳ������ */
				Tail = W->AdjV;          /* ��ǰ��β */
                AddQ (Q, W->AdjV);       /* W->AdjV����� */
			}
		}
		if ( V==Last ) { /* �����һ������һ�����㵯���� */
			Level++;     /* �������� */
			Last = Tail; /* ���µ�ǰ��βΪ�ò㱻���ʵ����һ������ */
		}
		if ( Level==SIX ) break; /* 6������������˳����� */
	} /* while����*/
	DestroyQueue( Q );
	return Count; /* ����ͳ������ */
}

void Six_Degrees_of_Separation( LGraph Graph ) 
{ /* ���ڽӱ�洢ͼ����ÿ������������ȿռ����� */
	Vertex V;
	int count;

	for( V=0; V<Graph->Nv; V++ ) { /* ��ͼ�е�ÿ������V */
		InitializeVisited( Graph->Nv );
		count = SDS_BFS( Graph, V );
		printf("����%d�����ȸ��Ǳ��� = %.2f%%\n", V, 100.0*(double)count/(double)Graph->Nv);
	}
}
