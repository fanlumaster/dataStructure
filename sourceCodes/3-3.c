bool Insert( List L, ElementType X, int i )
{ /* ��L��ָ��λ��iǰ����һ����Ԫ��X;λ��iԪ�ص�����λ���±���i-1 */
	Position j;

	if ( L->Last == MAXSIZE-1) {
		/* ��ռ����������ܲ��� */
		printf("����"); 
		return false; 
	}  
	if ( i<1 || i>L->Last+2 ) { 
    /* ������λ��ĺϷ��ԣ��Ƿ���1~n+1��nΪ��ǰԪ�ظ�������Last+1 */
		printf("λ�򲻺Ϸ�");
		return false; 
	} 
	for( j=L->Last; j>=i-1; j-- ) /*Lastָ���������Ԫ�� */
		L->Data[j+1] = L->Data[j]; /* ��λ��i���Ժ��Ԫ��˳������ƶ� */
	L->Data[i-1] = X;  /* ��Ԫ�ز����iλ���������±�Ϊi-1 */
	L->Last++;       /* Last��ָ�����Ԫ�� */
	return true; 
}
