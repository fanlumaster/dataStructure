#define KEYLENGTH 15                   /* �ؼ����ַ�������󳤶� */
typedef char ElementType[KEYLENGTH+1]; /* �ؼ����������ַ��� */
typedef int Index;                     /* ɢ�е�ַ���� */
/******** �����ǵ�3���е�����Ķ��� ********/
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** �����ǵ�3���е�����Ķ��� ********/

typedef struct TblNode *HashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б��㶨�� */
	int TableSize; /* �����󳤶� */
	List Heads;    /* ָ������ͷ�������� */
};
