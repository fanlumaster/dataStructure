void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
		/* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal( BT->Right );
    }
}
