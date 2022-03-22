void InorderTraversal( BinTree BT )
{
	BinTree T;
	Stack S = CreateStack(); /* �����ն�ջS��Ԫ������ΪBinTree */

	T = BT; /* �Ӹ������� */
	while( T || !IsEmpty(S) ){
		while( T ){ /* һֱ���󲢽���;���ѹ���ջ */
			Push(S, T); 
			T = T->Left; 
		}
		T = Pop(S); /* ��㵯����ջ */
        printf("%d ", T->Data); /*�����ʣ���ӡ��� */
		T = T->Right; /* ת�������� */
	}
}
