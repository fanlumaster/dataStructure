typedef Vertex ElementType;

void Initialization( SetType S, int N )
{ /* ���ϳ�ʼ�� */
	int i;
	for ( i=0; i<N; i++ )
		S[i] = -1;
}

void InputConnection( SetType S, int M )
{ /* ����M���ߣ������б������Ľ�㲢��ͬһ���� */
	Vertex U, V;    /* ��¼����Ľ�� */
	Vertex Root1, Root2;  /* ��¼���������ڵļ��ϵĸ���� */
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
{ /*���㼯��S����ͨ���ĸ��� */
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
	printf("��Ҫ�����·%d��\n", CountConnectedComponents( S, N )-1 );

	return 0;
}
