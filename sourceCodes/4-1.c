Position SequentialSearch ( List Tbl, ElementType K )
{ /* ��˳��洢�ı�Tbl�в��ҹؼ���ΪK������Ԫ�� */
	Position i;

    Tbl->Data[0] = K; /*�����ڱ�*/
    for( i = Tbl->Last; Tbl->Data[i] != K; i--);
    return i; /* ���ҳɹ���������Ԫ�����ڵ�Ԫ�±ꣻ���Ҳ��ɹ�����0 */
}
