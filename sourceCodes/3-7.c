#define ERROR NULL

Position Find( List L, ElementType X )
{
	Position p = L; /* pָ��L�ĵ�1����� */

	while ( p && p->Data!=X )
		p = p->Next;

	/* ������������ return p; �滻 */
	if ( p )
		return p;
	else
		return ERROR;
}
