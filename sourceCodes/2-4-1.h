/* 单向链表结点的定义 */

typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* 存储结点数据 */
	PtrToNode   Next; /* 指向下一个结点的指针 */
};

/* 结点空间申请 */
PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));

typedef PtrToNode List; /* 定义单链表类型 */
