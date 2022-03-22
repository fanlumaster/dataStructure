bool IsFull( MaxHeap H )
{
	return (H->Size == H->Capacity);
}

bool Insert( MaxHeap H, ElementType X )
{ /* 将元素X插入最大堆H，其中H->Data[0]已经定义为哨兵 */
    int i;
 
	if ( IsFull(H) ) { 
        printf("最大堆已满");
        return false;
    }
	i = ++H->Size; /* i指向插入后堆中的最后一个元素的位置 */
	for ( ; H->Data[i/2] < X; i/=2 )
        H->Data[i] = H->Data[i/2]; /* 上滤X */
	H->Data[i] = X; /* 将X插入 */
	return true;
}
