int Compare( int e1, int e2 )
{ /*�Ƚ�����ָ��e1��e2�����ݴ�С������������ֱ𷵻�1��-1��0 */
	if ( e1 > e2 ) return 1;       /* e1�󣬷���1       */
	else if ( e1 < e2 ) return -1; /* e2�󣬷���-1      */
	else  return 0;                /* e1��e2��ȣ�����0 */
}

void Attach( int coef, int expon, Polynomial *PtrRear )  
{ /* �����ڱ���������Ҫ�ı䵱ǰ������ʽβ��ָ���ֵ��  */
  /* ���Ժ������ݽ������ǽ��ָ��ĵ�ַ��*PtrRearָ��β��*/
	Polynomial P; 

	/* �����½�㣬����ֵ */
	P =(Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->expon = expon;
	P->link = NULL;
    /* ��Pָ����½����뵽��ǰ������ʽβ��ĺ���  */ 
	(*PtrRear)->link = P; 
	*PtrRear = P;   /* �޸�PtrRearֵ */
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	
	/* Ϊ�����ͷ���룬�Ȳ���һ����ʱ�ս����Ϊ�������ʽ����ͷ */
	rear = (Polynomial)malloc(sizeof(struct PolyNode));  
	front = rear; /* ��front ��¼�������ʽ����ͷ��� */
	while ( P1 && P2 )  /* ����������ʽ���з����������ʱ */
		switch ( Compare(P1->expon, P2->expon) ) {
			case 1: /* P1�е�������ָ���ϴ� */
				Attach( P1->coef, P1->expon, &rear);
				P1 = P1->link;
				break;
			case -1: /* P2�е�������ָ���ϴ� */
				Attach(P2->coef, P2->expon, &rear); 
				P2 = P2->link;
				break;
			case 0:  /* ��������ָ����� */
				sum = P1->coef + P2->coef;
				if ( sum ) Attach(sum, P1->expon, &rear);
				P1 = P1->link; 
				P2 = P2->link;
				break;
	}
	/* ��δ���������һ������ʽ�����нڵ����θ��Ƶ��������ʽ��ȥ */
	for ( ; P1; P1 = P1->link ) Attach(P1->coef, P1->expon, &rear);
	for ( ; P2; P2 = P2->link ) Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL; 
	temp = front;
	front = front->link; /*��frontָ��������ʽ��һ�������� */
	
	free(temp);    /* �ͷ���ʱ�ձ�ͷ��� */
	return front;
} 
