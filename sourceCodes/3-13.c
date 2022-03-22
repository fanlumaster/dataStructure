bool IsEmpty( Stack S )
{
	return (S->Top == -1);
}

ElementType Pop( Stack S )
{
	if ( IsEmpty(S) ) {
		printf("堆栈空");
		return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
	}
	else 
		return ( S->Data[(S->Top)--] );
}
