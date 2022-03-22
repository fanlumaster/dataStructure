typedef struct HTNode *HuffmanTree; /* 哈夫曼树类型 */
struct HTNode{ /* 哈夫曼树结点定义 */
	int Weight;         /* 结点权值 */
	HuffmanTree Left;   /* 指向左子树 */
	HuffmanTree Right;  /* 指向右子树 */
};

HuffmanTree Huffman( MinHeap H )
{ /* 这里最小堆的元素类型为HuffmanTree */
  /* 假设H->Size个权值已经存在H->Data[]->Weight里 */
	int i, N;
	HuffmanTree T;

    BuildHeap(H); /* 将H->Data[]按权值Weight调整为最小堆 */
	N = H->Size;
    for ( i=1; i<N; i++ ) { /* 做H->Size-1次合并 */
        T = (HuffmanTree)malloc(sizeof(struct HTNode)); /* 建立一个新的根结点 */
        T->Left = DeleteMin(H);  /* 从最小堆中删除一个结点，作为新T的左子结点 */
        T->Right = DeleteMin(H); /* 从最小堆中删除一个结点，作为新T的右子结点 */
        T->Weight = T->Left->Weight+T->Right->Weight; /* 计算新权值 */
        Insert( H, T ); /* 将新T插入最小堆 */
	}	
	return DeleteMin(H); /* 最小堆中最后一个元素即是指向哈夫曼树根结点的指针 */
}
