bool Insert( List L, ElementType X, int i )
{ /* ����Ĭ��L��ͷ��� */
	Position tmp, pre;
int cnt = 0;
	
/* ����λ��Ϊi-1�Ľ�� */		
	pre = L;      /* preָ���ͷ */
	while ( pre && cnt<i-1 ) {
		    pre = pre->Next;
		    cnt++;  
	}
	if ( pre==NULL || cnt!=i-1) { /* ���ҽ�㲻��L�� */
		printf("����λ�ò�������\n");
		return false;
	}
	else { /* �ҵ��˴������ǰһ�����pre����iΪ1��pre��ָ���ͷ */
		/* �����½�� */
		tmp=(Position)malloc(sizeof(struct LNode)); /*���롢��װ���*/
		tmp->Data = X; 
		tmp->Next = pre->Next;
		pre->Next = tmp;
		return true;
	}
}
