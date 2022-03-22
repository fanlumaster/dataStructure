void InorderTraversal( BinTree BT )
{
	BinTree T;
	Stack S = CreateStack(); /* 创建空堆栈S，元素类型为BinTree */

	T = BT; /* 从根结点出发 */
	while( T || !IsEmpty(S) ){
		while( T ){ /* 一直向左并将沿途结点压入堆栈 */
			Push(S, T); 
			T = T->Left; 
		}
		T = Pop(S); /* 结点弹出堆栈 */
        printf("%d ", T->Data); /*（访问）打印结点 */
		T = T->Right; /* 转向右子树 */
	}
}
