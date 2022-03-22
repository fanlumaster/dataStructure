#define ERROR -1

Position Find( List L, ElementType X )
{
	Position i = 0;

	while( i <= L->Last && L->Data[i]!= X )
		i++;
	if ( i > L->Last )  return ERROR; /* 如果没找到，返回错误信息 */
	else  return i;  /* 找到后返回的是存储位置 */
}
