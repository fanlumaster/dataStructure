typedef struct HTNode *HuffmanTree; /* ������������ */
struct HTNode{ /* ����������㶨�� */
	int Weight;         /* ���Ȩֵ */
	HuffmanTree Left;   /* ָ�������� */
	HuffmanTree Right;  /* ָ�������� */
};

HuffmanTree Huffman( MinHeap H )
{ /* ������С�ѵ�Ԫ������ΪHuffmanTree */
  /* ����H->Size��Ȩֵ�Ѿ�����H->Data[]->Weight�� */
	int i, N;
	HuffmanTree T;

    BuildHeap(H); /* ��H->Data[]��ȨֵWeight����Ϊ��С�� */
	N = H->Size;
    for ( i=1; i<N; i++ ) { /* ��H->Size-1�κϲ� */
        T = (HuffmanTree)malloc(sizeof(struct HTNode)); /* ����һ���µĸ���� */
        T->Left = DeleteMin(H);  /* ����С����ɾ��һ����㣬��Ϊ��T�����ӽ�� */
        T->Right = DeleteMin(H); /* ����С����ɾ��һ����㣬��Ϊ��T�����ӽ�� */
        T->Weight = T->Left->Weight+T->Right->Weight; /* ������Ȩֵ */
        Insert( H, T ); /* ����T������С�� */
	}	
	return DeleteMin(H); /* ��С�������һ��Ԫ�ؼ���ָ���������������ָ�� */
}
