int GetHeight( BinTree BT )
{
	int HL, HR, MaxH;

    if( BT ) {
        HL = GetHeight(BT->Left);   /* ���������ĸ߶� */
        HR = GetHeight(BT->Right);  /* ���������ĸ߶� */
        MaxH = HL > HR ? HL : HR;   /* ȡ���������ϴ�ĸ߶� */
        return ( MaxH + 1 );        /* �������ĸ߶� */
	}
	else  return 0; /* �����߶�Ϊ0 */
}
