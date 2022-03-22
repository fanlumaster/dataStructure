bool VIPIsEmpty( Queue Q )
{
	return (Q->VIPSize == 0);
}

ElementType DeleteVIP( Queue Q )
{ /* 令VIP子列队首的客户出列 */
	ElementType X;
	Position P;

	if ( !VIPIsEmpty(Q) ) { /* 如果存在VIP客户 */
		/* 获得队首客户在顾客队列中的位置 */
		P = Q->VIPCustomer[Q->VIPFront]; 
		/* 将该位置从VIP子列中删除 */
		Q->VIPFront++;
		Q->VIPSize--;
		Q->Data[P].VIP = -1; /* 懒惰删除顾客队列中的VIP */
		X.T = Q->Data[P].T;
		X.P = Q->Data[P].P;
	}
	else  /* 如果没有VIP客户，则做普通出列 */
		X = DeleteQ(Q);
	
	return X;
}
