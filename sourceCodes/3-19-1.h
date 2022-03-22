#define MAXMATRIXSIZE 100 /* �Թ�������������� */
#define MAXSTACKSIZE  100 /* ��ջ����ģ */

struct Offsets { /* ƫ�����ṹ���� */
	short int Vert;   /* ����ƫ�� */
	short int Horiz;  /* ����ƫ�� */
};

struct MazePosition {  /* �Թ��е�λ�ýṹ */
	short int Row; /* �к� */
	short int Col; /* �к� */
	short int Dir; /* ��Ӧƫ��������ķ���� */
};
typedef struct MazePosition ElementType; /* ��ջԪ������ */

/****       ���²������ڽ̲�������      ****/
typedef int Position;
struct SNode {
	ElementType *Data; /* �洢Ԫ�ص����� */
	Position Top;      /* ջ��ָ�� */
	int MaxSize;       /* ��ջ������� */
};
typedef struct SNode *Stack;
/****       ���ϲ������ڽ̲�������      ****/
/* ����Ԯ������3.11-13����ӦCreateStack��IsEmpty��IsFull��Push��Pop */
/* ע�⣺���ڴӶ�ջ������·���Ƿ���ģ��������Ǵӳ�������ڷ��������ȽϷ��㣬
  ���ﲻ����ֱ�Ӳ��ݶ�ջ�ڲ�Ԫ�ء�*/
