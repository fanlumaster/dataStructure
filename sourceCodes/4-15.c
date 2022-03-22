Position FindMax( BinTree BST )
{
    if( BST ) 
        while( BST->Right )
            BST = BST->Right; /* 沿右分支一直向下，直到最右端点 */
    return BST;
}
