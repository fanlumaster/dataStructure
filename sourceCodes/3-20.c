void Path( int Maze[][MAXMATRIXSIZE], int EXITROW, int EXITCOL )
{ /* Ĭ���Թ�Maze�����Ϊ(1, 1)������Ϊ(EXITROW, EXITCOL) */
	/* �Թ�8�������ƫ�������� */
	struct Offsets Move[8] =
	{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE]; /* ���λ���Ƿ��߹� */
	Stack S;  /* �������Ķ�ջ */
	struct MazPosition P;
	short int Row, Col, NextRow, NextCol, Dir;
	bool Found = false;

	S= CreateStack( MAXSTACKSIZE ); /* ��ʼ���ն�ջ */

	Mark[EXITROW][EXITCOL] = 1; /* �ӳ���λ�ÿ�ʼ�����Ϊ�߹� */
	/* ������λ�ü���һ����������ջ */
	P.Row = EXITROW; 
	P.Col = EXITCOL;
	P.Dir = 0;
	Push( S, P );
    
	while ( !IsEmpty(S) && !Found ) { /* ��ջ�ǿ���û�ҵ����ʱ */
		P = Pop(S); /* ȡ��ջ��Ԫ��Ϊ��ǰλ�� */
		Row = P.Row; Col = P.Col; Dir = P.Dir;
		while ( Dir < 8 && !Found ) {/* �����з����̽��û�ҵ����ʱ */
			/* ��������һ������Dir�ƶ� */
			NextRow = Row + Move[Dir].Vert;
			NextCol = Col + Move[Dir].Horiz;
			if ( NextRow==1 && NextCol==1 )  
				/* ���������� */
				Found = true;
			else  /* ��һ��λ�ò������ */
				/* ����һ��λ�ÿ�ͨ����û�߹� */
				if ( !Maze[NextRow][NextCol] && !Mark[NextRow][NextCol] ){					
					Mark[NextRow][NextCol] = 1; /* ���Ϊ�߹� */
					/* ��ǰλ�ú���һ���������ջ */
					P.Row = Row;
					P.Col = Col;
					P.Dir = Dir + 1;
					Push(S, P);
					/* ���µ�ǰλ�ã��ӷ���0��ʼ */
					Row = NextRow; Col = NextCol; Dir = 0;
				} /* ����if */
				else ++Dir; /* ����·��ͨ�����ڵ�ǰλ�ó�����һ������ */
		} /* ����8����̽�� */
	} /* �������� */
	if ( Found ) { /* �ҵ�һ��·�����������·�� */
		printf("�ҵ�·������\n");
		printf("�� ��\n");
		printf("1  1\n"); /* ��ӡ��� */
		printf("%d  %d\n", Row, Col); /* ��Ҫ�������һ��δ���ջ */
		while ( !IsEmpty(S) ) {
			P = Pop(S);
			printf("%d  %d\n", P.Row, P.Col);
		}
	}
	else /* ��û�ҵ�·�� */
		printf("���Թ��޽⡣\n");
}
