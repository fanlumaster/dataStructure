/* ˫��������Ķ��� */

typedef struct DNode *PtrToDNode;
struct DNode {
	ElementType Data;     /* �洢������� */
	PtrToDNode  Next;     /* ָ����һ������ָ�� */
	PtrToDNode  Previous; /* ָ��ǰһ������ָ�� */
};
