void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
		/* �˴������BT���ķ��ʾ��Ǵ�ӡ���� */
        printf("%d ", BT->Data); /* ��������Ϊ���� */
        InorderTraversal( BT->Right );
    }
}
