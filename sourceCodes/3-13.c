bool IsEmpty( Stack S )
{
	return (S->Top == -1);
}

ElementType Pop( Stack S )
{
	if ( IsEmpty(S) ) {
		printf("��ջ��");
		return ERROR; /* ERROR��ElementType������ֵ����־���� */
	}
	else 
		return ( S->Data[(S->Top)--] );
}
