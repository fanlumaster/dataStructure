#define ERROR -1

ElementType FindKth( List L, int K )
{ /* 根据指定的位序K，返回L中相应元素 */
	Position p;
	int cnt = 1; /* 位序从1开始 */

	p = L; /* p指向L的第1个结点 */
	while ( p && cnt<K ) {
		p = p->Next;
		cnt++;  
	}
	if ( (cnt==K) && p )
		return p->Data; /* 找到第K个 */
	else
		return ERROR;   /* 否则返回错误信息 */
}
