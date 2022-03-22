#define ERROR -1 /* �����ʶӦ���ݾ����������Ϊ���в����ܳ��ֵ�Ԫ��ֵ */

bool IsEmpty( MaxHeap H )
{
	return (H->Size == 0);
}

ElementType DeleteMax( MaxHeap H )
{ /* ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� */
    int Parent, Child;
    ElementType MaxItem, X;

    if ( IsEmpty(H) ) {
        printf("������Ϊ��");
        return ERROR;
    }

    MaxItem = H->Data[1]; /* ȡ��������ŵ����ֵ */
    /* �����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²��� */
    X = H->Data[H->Size--]; /* ע�⵱ǰ�ѵĹ�ģҪ��С */
	for( Parent=1; Parent*2<=H->Size; Parent=Child ) {
		Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= H->Data[Child] ) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;

    return MaxItem;
} 
