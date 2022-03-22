void LevelorderTraversal ( BinTree BT )
{ 
	Queue Q; 
	BinTree T;

	if ( !BT ) return; /* 若是空树则直接返回 */
	
	Q = CreatQueue(); /* 创建空队列Q */
	AddQ( Q, BT );
	while ( !IsEmpty(Q) ) {
		T = DeleteQ( Q );
		printf("%d ", T->Data); /* 访问取出队列的结点 */
		if ( T->Left )   AddQ( Q, T->Left );
		if ( T->Right )  AddQ( Q, T->Right );
	}
}
