void LevelorderTraversal ( BinTree BT )
{ 
	Queue Q; 
	BinTree T;

	if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */
	
	Q = CreatQueue(); /* �����ն���Q */
	AddQ( Q, BT );
	while ( !IsEmpty(Q) ) {
		T = DeleteQ( Q );
		printf("%d ", T->Data); /* ����ȡ�����еĽ�� */
		if ( T->Left )   AddQ( Q, T->Left );
		if ( T->Right )  AddQ( Q, T->Right );
	}
}
