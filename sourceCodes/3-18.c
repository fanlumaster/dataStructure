bool IsEmpty( Queue Q )
{
	return ( Q->Front == NULL);
}

ElementType DeleteQ( Queue Q )
{
	Position FrontCell; 
	ElementType FrontElem;
	
	if  ( IsEmpty(Q) ) {
		printf("���п�");
		return ERROR;
	}
	else {
		FrontCell = Q->Front;
		if ( Q->Front == Q->Rear ) /* ������ֻ��һ��Ԫ�� */
			Q->Front = Q->Rear = NULL; /* ɾ���������Ϊ�� */
		else                     
			Q->Front = Q->Front->Next;
		FrontElem = FrontCell->Data;

		free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
		return  FrontElem;
	}
}
