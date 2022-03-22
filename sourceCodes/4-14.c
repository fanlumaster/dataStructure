Position FindMin( BinTree BST )
{ /* 最小元素在最左端点 */
    if( !BST ) return NULL; /* 空的二叉搜索树，返回NULL */
    else if( !BST->Left ) return BST; /* 找到最左端点并返回 */
    else return FindMin( BST->Left ); /* 沿左分支递归查找 */
}
