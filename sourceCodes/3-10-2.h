typedef enum {Head, Term} NodeTag;

struct TermNode { /* ����Ԫ�ؽ�� */
	int Row, Col;
	ElementType Value;
};

typedef struct MNode *PtrToMNode;
struct MNode { /* �����㶨�� */
	PtrToMNode Down, Right;
	NodeTag Tag;
	union { /* Head��ӦNextָ�룻Term��Ӧ����Ԫ�ؽ�� */
		PtrToMNode Next;
		struct TermNode Term;
	} URegion;
};
typedef PtrToMNode Matrix; /* ϡ��������Ͷ��� */
Matrix  HeadNode [MAXSIZE]; /* MAXSIZE�Ǿ�������0Ԫ�ظ��� */
