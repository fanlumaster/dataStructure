typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType *Data; /* �洢Ԫ�ص����� */
	Position Top;      /* ջ��ָ�� */
	int MaxSize;       /* ��ջ������� */
};
typedef PtrToSNode Stack;
