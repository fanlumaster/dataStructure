void PreorderPrintLeaves( BinTree BT )
{
    if( BT ) {
        if ( !BT->Left && !BT->Right ) /* ���BT�����Ҷ�� */
            printf("%d ", BT->Data );
        PreorderPrintLeaves ( BT->Left );
        PreorderPrintLeaves ( BT->Right );
    }
}
