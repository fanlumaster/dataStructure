#define EmptyQ -1 /* 队列空的信号 */

ElementType DeleteQ( Queue Q )
{ /* 令Q队首的顾客出列 */
	ElementType X;

    /* 将位于队列前端的被懒惰删除的顾客真正删除 */
	while ( Q->Data[Q->Front].VIP == -1 )
		Q->Front++;
	if ( IsEmpty(Q) ) { /* 如果清除后发现队列已空，返回空信号 */
		X.T = EmptyQ;
		return X;
	}
	if ( Q->Data[Q->Front].VIP == 1 )
		X = DeleteVIP(Q); /* 令队首的VIP客户出列 */
	else {  /* 普通顾客出列 */
		X.T = Q->Data[Q->Front].T;
		X.P = Q->Data[Q->Front].P;
	}
    /* 删除队首的顾客 */
	Q->Front++;
	return X;
}
