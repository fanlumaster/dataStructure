void PercDown( MaxHeap H, int p )
{ /* ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    ElementType X;

    X = H->Data[p]; /* ȡ��������ŵ�ֵ */
	for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
		Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= H->Data[Child] ) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}

void BuildHeap( MaxHeap H )
{ /* ����H->Data[]�е�Ԫ�أ�ʹ�������ѵ�������  */
  /* �����������H->Size��Ԫ���Ѿ�����H->Data[]�� */

	int i;

	/* �����һ�����ĸ��ڵ㿪ʼ���������1 */
	for( i = H->Size/2; i>0; i-- )
		PercDown( H, i );
}
