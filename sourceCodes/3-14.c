bool Push( Stack S, ElementType X, int Tag )
{ /* Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2 */
	if ( S->Top2-S->Top1 == 1) { /* ��ջ�� */
		printf("��ջ��\n");
		return false;
	}
	else {
		if ( Tag == 1 ) /* �Ե�һ����ջ���� */
			S->Data[++(S->Top1)] = X;
		else              /* �Եڶ�����ջ���� */
			S->Data[--(S->Top2)] = X;
		return true;
	}
}

ElementType Pop( Stack S, int Tag )
{ /* Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2 */
	if ( Tag == 1 ) { /* �Ե�һ����ջ���� */
		if ( S->Top1 == -1 ) { /* ��ջ1�� */
			printf("��ջ1��\n");
			return ERROR;
		}
		else return S->Data[(S->Top1)--];
	}
	else { /* �Եڶ�����ջ���� */
		if ( S->Top2 == S->MaxSize ) { /* ��ջ2�� */
			printf("��ջ2��\n");
			return ERROR;
		}
		else  return S->Data[(S->Top2)++];
	}
}
