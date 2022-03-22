typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode *PtrToQNode;
struct QNode {
	Position Front, Rear;  /* 队列的头、尾指针 */
	int MaxSize;           /* 队列最大容量 */
};
typedef PtrToQNode Queue;
