Position FindMax( BinTree BST )
{
    if( BST ) 
        while( BST->Right )
            BST = BST->Right; /* ���ҷ�֧һֱ���£�ֱ�����Ҷ˵� */
    return BST;
}
