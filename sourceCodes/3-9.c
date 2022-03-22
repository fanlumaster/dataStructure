bool Insert( List L, ElementType X, int i )
{ /* 这里默认L有头结点 */
	Position tmp, pre;
int cnt = 0;
	
/* 查找位序为i-1的结点 */		
	pre = L;      /* pre指向表头 */
	while ( pre && cnt<i-1 ) {
		    pre = pre->Next;
		    cnt++;  
	}
	if ( pre==NULL || cnt!=i-1) { /* 所找结点不在L中 */
		printf("插入位置参数错误\n");
		return false;
	}
	else { /* 找到了待插结点的前一个结点pre；若i为1，pre就指向表头 */
		/* 插入新结点 */
		tmp=(Position)malloc(sizeof(struct LNode)); /*申请、填装结点*/
		tmp->Data = X; 
		tmp->Next = pre->Next;
		pre->Next = tmp;
		return true;
	}
}
