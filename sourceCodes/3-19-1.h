#define MAXMATRIXSIZE 100 /* 迷宫矩阵最大行列数 */
#define MAXSTACKSIZE  100 /* 堆栈最大规模 */

struct Offsets { /* 偏移量结构定义 */
	short int Vert;   /* 纵向偏移 */
	short int Horiz;  /* 横向偏移 */
};

struct MazePosition {  /* 迷宫中的位置结构 */
	short int Row; /* 行号 */
	short int Col; /* 列号 */
	short int Dir; /* 对应偏移量数组的方向号 */
};
typedef struct MazePosition ElementType; /* 堆栈元素类型 */

/****       以下不出现在教材正文中      ****/
typedef int Position;
struct SNode {
	ElementType *Data; /* 存储元素的数组 */
	Position Top;      /* 栈顶指针 */
	int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;
/****       以上不出现在教材正文中      ****/
/* 正文援引代码3.11-13，对应CreateStack、IsEmpty、IsFull、Push和Pop */
/* 注意：由于从堆栈弹出的路径是反向的，所以我们从出口向入口反向搜索比较方便，
  这里不可以直接操纵堆栈内部元素。*/
