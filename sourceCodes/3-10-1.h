typedef struct GNode *PtrToGNode;
typedef PtrToGNode GList;
struct GNode {
	int Tag; /* 标志域：0表示该结点是单元素；1表示该结点是广义表 */
	union {
		/* 子表指针域Sublist与单元素数据域Data复用，即共用存储空间 */
		ElementType Data;
		GList    Sublist;
	} URegion;
	PtrPtrToGNode Next; /* 指向后继结点 */
};
