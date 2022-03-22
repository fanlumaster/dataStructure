bool IsFull( MaxHeap H )
{
	return (H->Size == H->Capacity);
}

bool Insert( MaxHeap H, ElementType X )
{ /* ��Ԫ��X��������H������H->Data[0]�Ѿ�����Ϊ�ڱ� */
    int i;
 
	if ( IsFull(H) ) { 
        printf("��������");
        return false;
    }
	i = ++H->Size; /* iָ��������е����һ��Ԫ�ص�λ�� */
	for ( ; H->Data[i/2] < X; i/=2 )
        H->Data[i] = H->Data[i/2]; /* ����X */
	H->Data[i] = X; /* ��X���� */
	return true;
}
