#define ERROR -1

Position Find( List L, ElementType X )
{
	Position i = 0;

	while( i <= L->Last && L->Data[i]!= X )
		i++;
	if ( i > L->Last )  return ERROR; /* ���û�ҵ������ش�����Ϣ */
	else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}
