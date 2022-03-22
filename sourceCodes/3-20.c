void Path( int Maze[][MAXMATRIXSIZE], int EXITROW, int EXITCOL )
{ /* 默认迷宫Maze的入口为(1, 1)，出口为(EXITROW, EXITCOL) */
	/* 迷宫8个方向的偏移量数组 */
	struct Offsets Move[8] =
	{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE]; /* 标记位置是否走过 */
	Stack S;  /* 辅助求解的堆栈 */
	struct MazPosition P;
	short int Row, Col, NextRow, NextCol, Dir;
	bool Found = false;

	S= CreateStack( MAXSTACKSIZE ); /* 初始化空堆栈 */

	Mark[EXITROW][EXITCOL] = 1; /* 从出口位置开始，标记为走过 */
	/* 将出口位置及下一个方向放入堆栈 */
	P.Row = EXITROW; 
	P.Col = EXITCOL;
	P.Dir = 0;
	Push( S, P );
    
	while ( !IsEmpty(S) && !Found ) { /* 当栈非空且没找到入口时 */
		P = Pop(S); /* 取出栈顶元素为当前位置 */
		Row = P.Row; Col = P.Col; Dir = P.Dir;
		while ( Dir < 8 && !Found ) {/* 当还有方向可探且没找到入口时 */
			/* 尝试往下一个方向Dir移动 */
			NextRow = Row + Move[Dir].Vert;
			NextCol = Col + Move[Dir].Horiz;
			if ( NextRow==1 && NextCol==1 )  
				/* 如果到达入口 */
				Found = true;
			else  /* 下一个位置不是入口 */
				/* 若下一个位置可通，且没走过 */
				if ( !Maze[NextRow][NextCol] && !Mark[NextRow][NextCol] ){					
					Mark[NextRow][NextCol] = 1; /* 标记为走过 */
					/* 当前位置和下一个方向存入栈 */
					P.Row = Row;
					P.Col = Col;
					P.Dir = Dir + 1;
					Push(S, P);
					/* 更新当前位置，从方向0开始 */
					Row = NextRow; Col = NextCol; Dir = 0;
				} /* 结束if */
				else ++Dir; /* 若此路不通，则在当前位置尝试下一个方向 */
		} /* 结束8方向探测 */
	} /* 结束搜索 */
	if ( Found ) { /* 找到一个路径，并输出该路径 */
		printf("找到路径如下\n");
		printf("行 列\n");
		printf("1  1\n"); /* 打印入口 */
		printf("%d  %d\n", Row, Col); /* 不要忘记最后一步未入堆栈 */
		while ( !IsEmpty(S) ) {
			P = Pop(S);
			printf("%d  %d\n", P.Row, P.Col);
		}
	}
	else /* 若没找到路径 */
		printf("该迷宫无解。\n");
}
