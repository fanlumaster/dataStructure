typedef int ElementType; /* 假设结点数据是整数 */
#define NoInfo 0         /* 用0表示没有结点 */

BinTree CreatBinTree()
{
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreatQueue(); /* 创建空队列 */
	
	/* 建立第1个结点，即根结点 */
	scanf("%d", &Data);
	if( Data != NoInfo ){
		/* 分配根结点单元，并将结点地址入队 */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ( Q, BT );
	}
	else return NULL; /* 若第1个数据就是0，返回空树 */

	while( !IsEmpty(Q) ){
		T = DeleteQ(Q); /* 从队列中取出一结点地址*/
		scanf("%d", &Data); /* 读入T的左孩子 */
		if( Data == NoInfo ) T->Left = NULL;
		else {  /* 分配新结点，作为出队结点左孩子；新结点入队 */
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ( Q, T->Left );
		}
		scanf("%d", &Data); /* 读入T的右孩子 */
		if( Data == NoInfo ) T->Right = NULL;
		else {  /* 分配新结点，作为出队结点右孩子；新结点入队 */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ( Q, T->Right );
		}
	} /* 结束while */
	return BT;
}
