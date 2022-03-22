bool IsFull( Stack S )
{
	return (S->Top == S->MaxSize-1);
}

bool Push( Stack S, ElementType X )
{
	if ( IsFull(S) ) {
		printf("��ջ��");
		return false;
	}
	else {
		S->Data[++(S->Top)] = X;
        return true;
    }
}
