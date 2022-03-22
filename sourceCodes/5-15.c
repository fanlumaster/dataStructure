void Show( HashTable H, double percent )
{
	int diffwordcount = 0;    /* 不同的单词数量 */
	int maxf = 0;             /* 最大的词频 */
	int *diffwords;           /* 每个词频对应的不同单词数量 */
	int maxCollision = 0;     /* 最大冲突次数，初始化为0 */
	int minCollision = 100;   /* 最小冲突次数，初始化为100 */
	Position L;
	int i, j, k, lowerbound, count = 0;

	for( i=0; i<H->TableSize; i++ ) {
		/* 求不同的单词数量 */
		diffwordcount += H->Heads[i].Count; /* 头结点Count统计链表长度 */
		/* 统计最大和最小冲突次数 */
		if( maxCollision<H->Heads[i].Count )
			maxCollision = H->Heads[i].Count;
		if( minCollision>H->Heads[i].Count )
			minCollision = H->Heads[i].Count;				
		/* 求最大的词频 */
		L = H->Heads[i].Next; /* 从每个链表的表头开始 */
		while( L ){ /* 遍历链表 */
			if( maxf<L->Count )  maxf = L->Count;
			L = L->Next;
		}
	} /* 结束for循环 */
 
	printf("共有 %d 个不同的单词，词频最大是 %d；\n", diffwordcount, maxf);
	printf("最大冲突次数是 %d, 最小冲突次数是 %d.\n", maxCollision, minCollision);			
            
	/* 求每个词频等级拥有的不同单词数量 */         
	/* 根据最大的词频，分配一个整数数组 */
	diffwords = (int *)malloc((maxf+1)*sizeof(int));
	/* 统计词频从1到maxf的单词数量 */
	for( i=0; i<=maxf; i++ ) 
		diffwords[i] = 0;   
	for( i=0; i<H->TableSize; i++ ) {
		L = H->Heads[i].Next; 
		while( L ){ /* 遍历链表 */
			diffwords[L->Count]++; /* 该词频增加一个单词 */
			L = L->Next;
		}
	}
            
	/* 求特定的词频，使得大于等于该词频的单词总和超过给定的比例 */
	lowerbound = (int)(diffwordcount * percent);
	for ( i=maxf; i>=1 && count<lowerbound; i-- )
		count += diffwords[i];
	/* 按词频从大到小输出单词 */
	for( j=maxf; j>=i; j-- ) { /* 对每个词频 */
		for( k=0; k<H->TableSize; k++ ) { /* 遍历整个散列表 */
			L = H->Heads[k].Next; 
			while( L ){
				if( j==L->Count ) /* 发现一个单词的词频与当前词频相等 */
					/* 输出该单词及词频 */
					printf(" %-15s : %d \n", L->Data, L->Count);
				L = L->Next;
			}
		}
	}
	free( diffwords );
}

