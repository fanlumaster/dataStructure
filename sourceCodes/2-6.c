int FactorialSum( List L )
{ /* ������L�����н��Data�Ľ׳˺� */
  /* ����Ĭ�����н���Dataֵ�Ǹ� */
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
