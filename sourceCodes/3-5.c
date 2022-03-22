int Length( List L )
{
	Position p;
	int cnt = 0; /* 初始化计数器 */

	p = L;  /* p指向表的第一个结点 */
	while ( p ) { 
		p = p->Next; 
		cnt++; /* 当前p指向的是第cnt个结点*/
	}   

	return cnt;
}
