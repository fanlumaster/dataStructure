typedef int Position;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
typedef PtrToLNode List;
