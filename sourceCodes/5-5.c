bool Insert( HashTable H, ElementType Key )
{
	Position Pos = Find( H, Key ); /* 先检查Key是否已经存在 */

	if( H->Cells[Pos].Info != Legitimate ) { /* 如果这个单元没有被占，说明Key可以插入在此 */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
        /*字符串类型的关键词需要 strcpy 函数!! */
		return true;
	}
	else {
		printf("键值已存在");
		return false;
	}
}
