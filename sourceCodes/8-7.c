bool VIPIsEmpty( Queue Q )
{
	return (Q->VIPSize == 0);
}

ElementType DeleteVIP( Queue Q )
{ /* ��VIP���ж��׵Ŀͻ����� */
	ElementType X;
	Position P;

	if ( !VIPIsEmpty(Q) ) { /* �������VIP�ͻ� */
		/* ��ö��׿ͻ��ڹ˿Ͷ����е�λ�� */
		P = Q->VIPCustomer[Q->VIPFront]; 
		/* ����λ�ô�VIP������ɾ�� */
		Q->VIPFront++;
		Q->VIPSize--;
		Q->Data[P].VIP = -1; /* ����ɾ���˿Ͷ����е�VIP */
		X.T = Q->Data[P].T;
		X.P = Q->Data[P].P;
	}
	else  /* ���û��VIP�ͻ���������ͨ���� */
		X = DeleteQ(Q);
	
	return X;
}
