#define MaxVertexNum 100	/* ��󶥵�����Ϊ100 */
#define INFINITY 65535		/* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;		/* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;	    /* ����洢������������Ϊ�ַ��� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
	DataType Data[MaxVertexNum];      /* �涥������� */
    /* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */
