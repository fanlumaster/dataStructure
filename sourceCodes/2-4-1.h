/* ����������Ķ��� */

typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* �洢������� */
	PtrToNode   Next; /* ָ����һ������ָ�� */
};

/* ���ռ����� */
PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));

typedef PtrToNode List; /* ���嵥�������� */
