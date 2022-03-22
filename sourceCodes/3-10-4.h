typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType *Data; /* 存储元素的数组 */
	Position Top;      /* 栈顶指针 */
	int MaxSize;       /* 堆栈最大容量 */
};
typedef PtrToSNode Stack;
