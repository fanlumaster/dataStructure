bool Delete( List L, int i )
{   /* ����Ĭ��L��ͷ��� */
	Position tmp, pre;
    int cnt = 0;
	
    /* ����λ��Ϊi-1�Ľ�� */		
	pre = L;      /* preָ���ͷ */
	while ( pre && cnt<i-1 ) {
		    pre = pre->Next;
		    cnt++;  
	}
	if ( pre==NULL || cnt!=i-1 ||pre->Next==NULL) {
    /* ���ҽ���λ��Ϊi�Ľ�㲻��L�� */
		printf("����λ�ò�������\n");
		return false;
	} else { /* �ҵ��˴�ɾ����ǰһ�����pre */
		/* �����ɾ�� */
		tmp=pre->Next;
        pre->Next=tmp->Next;
		free(tmp);
		return true;
	}
}
