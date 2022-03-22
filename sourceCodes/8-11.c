int Kruskal( LGraph Graph, LGraph MST )
{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
	WeightType TotalWeight;
    int ECount, NextEdge;
	SetType VSet; /* 顶点数组 */
	Edge ESet;    /* 边数组 */

	InitializeVSet( VSet, Graph->Nv ); /* 初始化顶点并查集 */
	ESet = (Edge)malloc( sizeof(struct ENode)*Graph->Ne );
	InitializeESet( Graph, ESet ); /* 初始化边的最小堆 */
    /* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
    MST = CreateGraph(Graph->Nv);
    TotalWeight = 0; /* 初始化权重和     */
    ECount = 0;      /* 初始化收录的边数 */

	NextEdge = Graph->Ne; /* 原始边集的规模 */
	while ( ECount < Graph->Nv-1 ) {  /* 当收集的边不足以构成树时 */
		NextEdge = GetEdge( ESet, NextEdge ); /* 从边集中得到最小边的位置 */
		if (NextEdge < 0) /* 边集已空 */
			break;
        /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
		if ( CheckCycle( VSet, ESet[NextEdge].V1, ESet[NextEdge].V2 )==true ) {
            /* 将该边插入MST */
            InsertEdge( MST, ESet+NextEdge );
			TotalWeight += ESet[NextEdge].Weight; /* 累计权重 */
			ECount++; /* 生成树中边数加1 */
		}
	}
	if ( ECount < Graph->Nv-1 )
		TotalWeight = -1; /* 设置错误标记，表示生成树不存在 */

	return TotalWeight;
}
