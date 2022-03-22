Position SequentialSearch ( List Tbl, ElementType K )
{ /* 在顺序存储的表Tbl中查找关键字为K的数据元素 */
	Position i;

    Tbl->Data[0] = K; /*建立哨兵*/
    for( i = Tbl->Last; Tbl->Data[i] != K; i--);
    return i; /* 查找成功返回数据元素所在单元下标；查找不成功返回0 */
}
