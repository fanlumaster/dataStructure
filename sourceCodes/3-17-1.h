typedef struct Node *PtrToNode;
struct Node { /* �����еĽ�� */
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode *PtrToQNode;
struct QNode {
	Position Front, Rear;  /* ���е�ͷ��βָ�� */
	int MaxSize;           /* ����������� */
};
typedef PtrToQNode Queue;
