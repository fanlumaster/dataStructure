bool Delete( List L, int i )
{ /* ��L��ɾ��ָ��λ��i��Ԫ��,��Ԫ�������±�Ϊi-1 */
	Position j;

	if( i<1 || i>L->Last+1 ) { /* ���ձ�ɾ��λ��ĺϷ��� */
		printf("λ��%d������Ԫ��", i ); 
		return false; 
	}
	for( j=i; j<=L->Last; j++ )    
		L->Data[j-1] = L->Data[j]; /*��λ��i+1���Ժ��Ԫ��˳����ǰ�ƶ�*/
	L->Last--; /* Last��ָ�����Ԫ�� */
	return true;   
}
