#define EmptyQ -1 /* ���пյ��ź� */

ElementType DeleteQ( Queue Q )
{ /* ��Q���׵Ĺ˿ͳ��� */
	ElementType X;

    /* ��λ�ڶ���ǰ�˵ı�����ɾ���Ĺ˿�����ɾ�� */
	while ( Q->Data[Q->Front].VIP == -1 )
		Q->Front++;
	if ( IsEmpty(Q) ) { /* ���������ֶ����ѿգ����ؿ��ź� */
		X.T = EmptyQ;
		return X;
	}
	if ( Q->Data[Q->Front].VIP == 1 )
		X = DeleteVIP(Q); /* ����׵�VIP�ͻ����� */
	else {  /* ��ͨ�˿ͳ��� */
		X.T = Q->Data[Q->Front].T;
		X.P = Q->Data[Q->Front].P;
	}
    /* ɾ�����׵Ĺ˿� */
	Q->Front++;
	return X;
}
