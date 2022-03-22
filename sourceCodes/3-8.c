#define ERROR NULL /* 用空地址表示错误 */

List Insert( List L, ElementType X, int i )
{	Position tmp, pre;

	tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
	tmp->Data = X; 
	if ( i == 1 ) { /* 新结点插入在表头 */
		tmp->Next = L;
		return tmp; /* 返回新表头指针 */
    }
	else {
		/* 查找位序为i-1的结点 */		
        int cnt = 1;  /* 位序从1开始 */
	    pre = L;      /* pre指向L的第1个结点 */
	    while ( pre && cnt<i-1 ) {
		    pre = pre->Next;
		    cnt++;  
	    }
		if ( pre==NULL || cnt!=i-1) { /* 所找结点不在L中 */
			printf("插入位置参数错误\n");
			free(tmp);
			return ERROR;
		}
		else { /* 找到了待插结点的前一个结点pre */
			/* 插入新结点，并且返回表头L */
			tmp->Next = pre->Next;
			pre->Next = tmp;
			return L;
		}
	}
}
