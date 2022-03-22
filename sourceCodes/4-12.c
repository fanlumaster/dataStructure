Position Find( BinTree BST, ElementType X )
{
	if( !BST ) return NULL; /* 查找失败 */
	
	if( X > BST->Data ) 
		return Find( BST->Right, X ); /* 在右子树中递归查找 */
	else if( X < BST->Data ) 
		return Find( BST->Left, X );  /* 在左子树中递归查找 */
	else /* X == BST->Data */
		return BST;  /* 在当前结点查找成功，返回当前结点的地址 */
}
