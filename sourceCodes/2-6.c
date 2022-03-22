int FactorialSum( List L )
{ /* 求单链表L中所有结点Data的阶乘和 */
  /* 这里默认所有结点的Data值非负 */
	int Fact, Sum, i;
	PtrToNode P = L;

	Sum = 0;
	while ( P ) {
		Fact = 1;
		for ( i=2; i<=P->Data; i++ )
			Fact *= i;
		Sum += Fact;
		P = P->Next;
	}
	return Sum;
}
