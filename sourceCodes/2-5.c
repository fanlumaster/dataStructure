List Reverse( List L )
{ /* ��������L��ת */
	PtrToNode Old_head, New_head, Temp;

	Old_head = L;    /* ��ʼ����ǰ�ɱ�ͷΪL */
	New_head = NULL; /* ��ʼ����ת���±�ͷΪ�� */
	while ( Old_head )  { /* ���ɱ�Ϊ��ʱ */
		Temp = Old_head->Next;
		Old_head->Next = New_head;  
		New_head = Old_head; /* ����ǰ�ɱ�ͷ��תΪ�±�ͷ */
		Old_head = Temp;     /* ���¾ɱ�ͷ */
	}
	L = New_head; /* ����L */
	return L;
}
