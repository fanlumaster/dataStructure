Position FindMin( BinTree BST )
{ /* ��СԪ��������˵� */
    if( !BST ) return NULL; /* �յĶ���������������NULL */
    else if( !BST->Left ) return BST; /* �ҵ�����˵㲢���� */
    else return FindMin( BST->Left ); /* �����֧�ݹ���� */
}
