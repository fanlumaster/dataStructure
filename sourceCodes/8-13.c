bool CheckCycle( SetType VSet, Vertex V1, Vertex V2 )
{ /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
	Vertex Root1, Root2;

	Root1 = Find( VSet, V1 ); /* 得到V1所属的连通集名称 */
	Root2 = Find( VSet, V2 ); /* 得到V2所属的连通集名称 */

	if( Root1==Root2 ) /* 若V1和V2已经连通，则该边不能要 */
		return false;
	else { /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
		Union( VSet, Root1, Root2 );
		return true;
	}
}
