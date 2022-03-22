typedef struct People ElementType;
struct People { /* 顾客类型 */
	int T;		/* 顾客到达时间 */
	int P;		/* 顾客事务被处理的时间 */
};

typedef int Position;
struct QNode { /* 队列结点 */
	ElementType *Data;     /* 顾客数组 */
	Position Front, Rear;  /* 队列的头、尾指针 */
	int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

/* 以下函数的实现见代码3.17 */
Queue CreateQueue( int MaxSize );
bool IsFull( Queue Q );
bool AddQ( Queue Q, ElementType X );
bool IsEmpty( Queue Q );
ElementType DeleteQ( Queue Q );
