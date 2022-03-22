typedef int ElementType; /* ���������������� */
#define NoInfo 0         /* ��0��ʾû�н�� */

BinTree CreatBinTree()
{
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreatQueue(); /* �����ն��� */
	
	/* ������1����㣬������� */
	scanf("%d", &Data);
	if( Data != NoInfo ){
		/* �������㵥Ԫ����������ַ��� */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ( Q, BT );
	}
	else return NULL; /* ����1�����ݾ���0�����ؿ��� */

	while( !IsEmpty(Q) ){
		T = DeleteQ(Q); /* �Ӷ�����ȡ��һ����ַ*/
		scanf("%d", &Data); /* ����T������ */
		if( Data == NoInfo ) T->Left = NULL;
		else {  /* �����½�㣬��Ϊ���ӽ�����ӣ��½����� */
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ( Q, T->Left );
		}
		scanf("%d", &Data); /* ����T���Һ��� */
		if( Data == NoInfo ) T->Right = NULL;
		else {  /* �����½�㣬��Ϊ���ӽ���Һ��ӣ��½����� */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ( Q, T->Right );
		}
	} /* ����while */
	return BT;
}
