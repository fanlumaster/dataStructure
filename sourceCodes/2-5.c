List Reverse( List L )
{ /* 将单链表L逆转 */
	PtrToNode Old_head, New_head, Temp;

	Old_head = L;    /* 初始化当前旧表头为L */
	New_head = NULL; /* 初始化逆转后新表头为空 */
	while ( Old_head )  { /* 当旧表不为空时 */
		Temp = Old_head->Next;
		Old_head->Next = New_head;  
		New_head = Old_head; /* 将当前旧表头逆转为新表头 */
		Old_head = Temp;     /* 更新旧表头 */
	}
	L = New_head; /* 更新L */
	return L;
}
