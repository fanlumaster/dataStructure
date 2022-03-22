int CountConnectedComponents( LGraph Graph )
{ /* 计算图Graph中连通集的个数 */
	Vertex V;
	int cnt = 0;

	/* 将全局变量Visited[]初始化为false */
	InitializeVisited( Graph->Nv );
	/* 每一次DFS对应一个连通集 */
	for ( V=0; V<Graph->Nv; V++ ) {
		if ( !Visited[V] ) {
			DFS( Graph, V );
			cnt ++;
		}
	}
	return cnt;
}
