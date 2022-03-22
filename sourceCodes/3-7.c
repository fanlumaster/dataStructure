#define ERROR NULL

Position Find( List L, ElementType X )
{
	Position p = L; /* p指向L的第1个结点 */

	while ( p && p->Data!=X )
		p = p->Next;

	/* 下列语句可以用 return p; 替换 */
	if ( p )
		return p;
	else
		return ERROR;
}
