Position Find( BinTree BST, ElementType X )
{
    while( BST ) {
        if( X > BST->Data )
			BST = BST->Right;    /* 向右子树中移动，继续查找 */
        else if( X < BST->Data )
			BST = BST->Left;     /* 向左子树中移动，继续查找 */
        else /* X == BST->Data */
            break; /* 在当前结点查找成功，跳出循环 */
    }
    return BST; /* 返回找到的结点地址，或是NULL */
}
