List MakeEmpty()
{
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;

	return L;
}
