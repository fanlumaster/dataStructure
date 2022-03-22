typedef struct People ElementType;
struct People { /* �˿����� */
	int T;		/* �˿͵���ʱ�� */
	int P;		/* �˿����񱻴����ʱ�� */
};

typedef int Position;
struct QNode { /* ���н�� */
	ElementType *Data;     /* �˿����� */
	Position Front, Rear;  /* ���е�ͷ��βָ�� */
	int MaxSize;           /* ����������� */
};
typedef struct QNode *Queue;

/* ���º�����ʵ�ּ�����3.17 */
Queue CreateQueue( int MaxSize );
bool IsFull( Queue Q );
bool AddQ( Queue Q, ElementType X );
bool IsEmpty( Queue Q );
ElementType DeleteQ( Queue Q );
