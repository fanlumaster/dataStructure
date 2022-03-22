typedef enum {Head, Term} NodeTag;

struct TermNode { /* 非零元素结点 */
	int Row, Col;
	ElementType Value;
};

typedef struct MNode *PtrToMNode;
struct MNode { /* 矩阵结点定义 */
	PtrToMNode Down, Right;
	NodeTag Tag;
	union { /* Head对应Next指针；Term对应非零元素结点 */
		PtrToMNode Next;
		struct TermNode Term;
	} URegion;
};
typedef PtrToMNode Matrix; /* 稀疏矩阵类型定义 */
Matrix  HeadNode [MAXSIZE]; /* MAXSIZE是矩阵最大非0元素个数 */
