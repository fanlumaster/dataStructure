BinTree Delete( BinTree BST, ElementType X ) 
{ 
    Position Tmp; 

    if( !BST ) 
        printf("Ҫɾ����Ԫ��δ�ҵ�"); 
    else {
        if( X < BST->Data ) 
            BST->Left = Delete( BST->Left, X );   /* ���������ݹ�ɾ�� */
        else if( X > BST->Data ) 
			BST->Right = Delete( BST->Right, X ); /* ���������ݹ�ɾ�� */
		else { /* BST����Ҫɾ���Ľ�� */
			/* �����ɾ����������������ӽ�� */ 
			if( BST->Left && BST->Right ) {
				/* ��������������С��Ԫ�����ɾ����� */
				Tmp = FindMin( BST->Right );
				BST->Data = Tmp->Data;
				/* ����������ɾ����СԪ�� */
				BST->Right = Delete( BST->Right, BST->Data );
			}
			else { /* ��ɾ�������һ�������ӽ�� */
				Tmp = BST; 
                if( !BST->Left )       /* ֻ���Һ��ӻ����ӽ�� */
					BST = BST->Right; 
                else                   /* ֻ������ */
					BST = BST->Left;
				free( Tmp );
			}
		}
	}
    return BST;
}
