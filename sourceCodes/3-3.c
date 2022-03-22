bool Insert( List L, ElementType X, int i )
{ /* 在L的指定位序i前插入一个新元素X;位序i元素的数组位置下标是i-1 */
	Position j;

	if ( L->Last == MAXSIZE-1) {
		/* 表空间已满，不能插入 */
		printf("表满"); 
		return false; 
	}  
	if ( i<1 || i>L->Last+2 ) { 
    /* 检查插入位序的合法性：是否在1~n+1。n为当前元素个数，即Last+1 */
		printf("位序不合法");
		return false; 
	} 
	for( j=L->Last; j>=i-1; j-- ) /*Last指向序列最后元素 */
		L->Data[j+1] = L->Data[j]; /* 将位序i及以后的元素顺序向后移动 */
	L->Data[i-1] = X;  /* 新元素插入第i位序，其数组下标为i-1 */
	L->Last++;       /* Last仍指向最后元素 */
	return true; 
}
