BinTree Insert( BinTree BST, ElementType X )
{
    if( !BST ){ /* ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� */
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* ��ʼ��Ҫ����Ԫ�ص�λ�� */
        if( X < BST->Data )
            BST->Left = Insert( BST->Left, X );   /*�ݹ����������*/
        else  if( X > BST->Data )
            BST->Right = Insert( BST->Right, X ); /*�ݹ����������*/
        /* else X�Ѿ����ڣ�ʲô������ */
	}
    return BST;
}
