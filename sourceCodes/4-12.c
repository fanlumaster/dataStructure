Position Find( BinTree BST, ElementType X )
{
	if( !BST ) return NULL; /* ����ʧ�� */
	
	if( X > BST->Data ) 
		return Find( BST->Right, X ); /* ���������еݹ���� */
	else if( X < BST->Data ) 
		return Find( BST->Left, X );  /* ���������еݹ���� */
	else /* X == BST->Data */
		return BST;  /* �ڵ�ǰ�����ҳɹ������ص�ǰ���ĵ�ַ */
}
