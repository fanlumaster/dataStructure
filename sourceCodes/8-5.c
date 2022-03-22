typedef struct People ElementType;
struct People { 
	int T; 
	int P; 
    int VIP; /* VIP标志：1=VIP；0=普通；-1=删除 */
};

typedef int Position;
struct QNode { /* 队列结点 */
	ElementType *Data;     /* 顾客数组 */
	Position Front, Rear;  /* 队列的头、尾指针 */
	int MaxSize;           /* 队列最大容量 */
    /*--下面是VIP子列的相应元素--*/
	Position VIPFront, VIPRear;
	int *VIPCustomer;
	int VIPSize; /* 队列中VIP的数量 */
	/*------------------------*/
};
typedef struct QueueRecord *Queue;

bool VIPIsFull( Queue Q );          /* 判断VIP队列是否为满 */
bool AddVIP( Queue Q, Position P ); /* 对VIP客户的入列操作 */
bool VIPIsEmpty( Queue Q );         /* 判断VIP队列是否为空 */
ElementType DeleteVIP( Queue Q );   /* 对VIP客户的出列操作 */

Queue CreateQueue( int MaxSize );
bool IsFull( Queue Q );
bool AddQ( Queue Q, ElementType X );
bool IsEmpty( Queue Q );
ElementType DeleteQ( Queue Q );
