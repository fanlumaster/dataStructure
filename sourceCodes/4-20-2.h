typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
struct HNode {
	ElementType *Data; /* �洢Ԫ�ص����� */
	int Size;          /* ���е�ǰԪ�ظ��� */
	int Capacity;      /* �ѵ�������� */
};
typedef Heap MaxHeap; /* ���� */
typedef Heap MinHeap; /* ��С�� */
