void PreorderPrintLeaves( BinTree BT )
{
    if( BT ) {
        if ( !BT->Left && !BT->Right ) /* 如果BT结点是叶子 */
            printf("%d ", BT->Data );
        PreorderPrintLeaves ( BT->Left );
        PreorderPrintLeaves ( BT->Right );
    }
}
