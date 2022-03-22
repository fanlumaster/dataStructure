bool Delete( List L, int i )
{ /* 从L中删除指定位序i的元素,该元素数组下标为i-1 */
	Position j;

	if( i<1 || i>L->Last+1 ) { /* 检查空表及删除位序的合法性 */
		printf("位序%d不存在元素", i ); 
		return false; 
	}
	for( j=i; j<=L->Last; j++ )    
		L->Data[j-1] = L->Data[j]; /*将位序i+1及以后的元素顺序向前移动*/
	L->Last--; /* Last仍指向最后元素 */
	return true;   
}
