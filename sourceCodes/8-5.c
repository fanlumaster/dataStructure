typedef struct People ElementType;
struct People { 
	int T; 
	int P; 
    int VIP; /* VIP��־��1=VIP��0=��ͨ��-1=ɾ�� */
};

typedef int Position;
struct QNode { /* ���н�� */
	ElementType *Data;     /* �˿����� */
	Position Front, Rear;  /* ���е�ͷ��βָ�� */
	int MaxSize;           /* ����������� */
    /*--������VIP���е���ӦԪ��--*/
	Position VIPFront, VIPRear;
	int *VIPCustomer;
	int VIPSize; /* ������VIP������ */
	/*------------------------*/
};
typedef struct QueueRecord *Queue;

bool VIPIsFull( Queue Q );          /* �ж�VIP�����Ƿ�Ϊ�� */
bool AddVIP( Queue Q, Position P ); /* ��VIP�ͻ������в��� */
bool VIPIsEmpty( Queue Q );         /* �ж�VIP�����Ƿ�Ϊ�� */
ElementType DeleteVIP( Queue Q );   /* ��VIP�ͻ��ĳ��в��� */

Queue CreateQueue( int MaxSize );
bool IsFull( Queue Q );
bool AddQ( Queue Q, ElementType X );
bool IsEmpty( Queue Q );
ElementType DeleteQ( Queue Q );
