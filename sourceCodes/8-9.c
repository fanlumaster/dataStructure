int CountConnectedComponents( LGraph Graph )
{ /* ����ͼGraph����ͨ���ĸ��� */
	Vertex V;
	int cnt = 0;

	/* ��ȫ�ֱ���Visited[]��ʼ��Ϊfalse */
	InitializeVisited( Graph->Nv );
	/* ÿһ��DFS��Ӧһ����ͨ�� */
	for ( V=0; V<Graph->Nv; V++ ) {
		if ( !Visited[V] ) {
			DFS( Graph, V );
			cnt ++;
		}
	}
	return cnt;
}
