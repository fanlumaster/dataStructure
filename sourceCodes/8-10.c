typedef Vertex ElementType;

void Initialization( SetType S, int N )
{ /* 集合初始化 */
	int i;
	for ( i=0; i<N; i++ )
		S[i] = -1;
}

void InputConnection( SetType S, int M )
{ /* 读入M条边，并将有边相连的结点并入同一集合 */
	Vertex U, V;    /* 记录输入的结点 */
	Vertex Root1, Root2;  /* 记录输入结点所在的集合的根结点 */
	int i;

	for ( i=0; i<M; i++ ) {
		scanf("%d %d", &U, &V);
		Root1 = Find( S, U );
		Root2 = Find( S, V );
		if ( Root1 != Root2 )
			Union( S, Root1, Root2 );
	}
}

int CountConnectedComponents( SetType S, int N )
{ /*计算集合S中连通集的个数 */
	int i, cnt = 0;

	for ( i=0; i<N; i++ ) {
		if ( S[i] < 0 )
			cnt ++;
	}
	return cnt;
}

int main()
{
	SetType S;
	int N, M;

	scanf("%d %d", &N, &M);
	Initialization( S, N );
	InputConnection( S, M );
	printf("需要建设道路%d条\n", CountConnectedComponents( S, N )-1 );

	return 0;
}
