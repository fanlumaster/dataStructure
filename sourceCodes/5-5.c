bool Insert( HashTable H, ElementType Key )
{
	Position Pos = Find( H, Key ); /* �ȼ��Key�Ƿ��Ѿ����� */

	if( H->Cells[Pos].Info != Legitimate ) { /* ��������Ԫû�б�ռ��˵��Key���Բ����ڴ� */
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
        /*�ַ������͵Ĺؼ�����Ҫ strcpy ����!! */
		return true;
	}
	else {
		printf("��ֵ�Ѵ���");
		return false;
	}
}
