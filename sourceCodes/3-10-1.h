typedef struct GNode *PtrToGNode;
typedef PtrToGNode GList;
struct GNode {
	int Tag; /* ��־��0��ʾ�ý���ǵ�Ԫ�أ�1��ʾ�ý���ǹ���� */
	union {
		/* �ӱ�ָ����Sublist�뵥Ԫ��������Data���ã������ô洢�ռ� */
		ElementType Data;
		GList    Sublist;
	} URegion;
	PtrPtrToGNode Next; /* ָ���̽�� */
};
