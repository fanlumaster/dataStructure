int GetHeight( BinTree BT )
{
	int HL, HR, MaxH;

    if( BT ) {
        HL = GetHeight(BT->Left);   /* 求左子树的高度 */
        HR = GetHeight(BT->Right);  /* 求右子树的高度 */
        MaxH = HL > HR ? HL : HR;   /* 取左右子树较大的高度 */
        return ( MaxH + 1 );        /* 返回树的高度 */
	}
	else  return 0; /* 空树高度为0 */
}
