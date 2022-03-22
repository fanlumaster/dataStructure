bool Delete( List L, int i )
{   /* 这里默认L有头结点 */
	Position tmp, pre;
    int cnt = 0;
	
    /* 查找位序为i-1的结点 */		
	pre = L;      /* pre指向表头 */
	while ( pre && cnt<i-1 ) {
		    pre = pre->Next;
		    cnt++;  
	}
	if ( pre==NULL || cnt!=i-1 ||pre->Next==NULL) {
    /* 所找结点或位序为i的结点不在L中 */
		printf("插入位置参数错误\n");
		return false;
	} else { /* 找到了待删结点的前一个结点pre */
		/* 将结点删除 */
		tmp=pre->Next;
        pre->Next=tmp->Next;
		free(tmp);
		return true;
	}
}
