/* 双向链表结点的定义 */

typedef struct DNode *PtrToDNode;
struct DNode {
	ElementType Data;     /* 存储结点数据 */
	PtrToDNode  Next;     /* 指向下一个结点的指针 */
	PtrToDNode  Previous; /* 指向前一个结点的指针 */
};
