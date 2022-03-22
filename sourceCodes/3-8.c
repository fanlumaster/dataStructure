#define ERROR NULL /* �ÿյ�ַ��ʾ���� */

List Insert( List L, ElementType X, int i )
{	Position tmp, pre;

	tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
	tmp->Data = X; 
	if ( i == 1 ) { /* �½������ڱ�ͷ */
		tmp->Next = L;
		return tmp; /* �����±�ͷָ�� */
    }
	else {
		/* ����λ��Ϊi-1�Ľ�� */		
        int cnt = 1;  /* λ���1��ʼ */
	    pre = L;      /* preָ��L�ĵ�1����� */
	    while ( pre && cnt<i-1 ) {
		    pre = pre->Next;
		    cnt++;  
	    }
		if ( pre==NULL || cnt!=i-1) { /* ���ҽ�㲻��L�� */
			printf("����λ�ò�������\n");
			free(tmp);
			return ERROR;
		}
		else { /* �ҵ��˴������ǰһ�����pre */
			/* �����½�㣬���ҷ��ر�ͷL */
			tmp->Next = pre->Next;
			pre->Next = tmp;
			return L;
		}
	}
}
