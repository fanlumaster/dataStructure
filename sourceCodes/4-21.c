#define MAXDATA 1000  /* ��ֵӦ���ݾ����������Ϊ���ڶ������п���Ԫ�ص�ֵ */

MaxHeap CreateHeap( int MaxSize )
{ /* ��������ΪMaxSize�Ŀյ����� */

	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MAXDATA; /* ����"�ڱ�"Ϊ���ڶ������п���Ԫ�ص�ֵ*/

	return H;
}
