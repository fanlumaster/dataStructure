Position Find( BinTree BST, ElementType X )
{
    while( BST ) {
        if( X > BST->Data )
			BST = BST->Right;    /* �����������ƶ����������� */
        else if( X < BST->Data )
			BST = BST->Left;     /* �����������ƶ����������� */
        else /* X == BST->Data */
            break; /* �ڵ�ǰ�����ҳɹ�������ѭ�� */
    }
    return BST; /* �����ҵ��Ľ���ַ������NULL */
}
