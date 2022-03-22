#define MAXWORDLEN 80 /* ���е�����󳤶� */

int GetAWord( FILE *fp, ElementType word )
{
	char tempword[MAXWORDLEN+1], c;
	int len = 0; /* ���ʳ��� */

	c = fgetc(fp);
	while( !feof(fp) ){
		if( IsWordChar(c) )  /* ����ǺϷ��ĵ����ַ� */
			tempword[len++] = c;
		c = fgetc(fp);
		/* ��������ǰ�ķǷ��ַ������ԷǷ��ַ�����һ������*/
		if( len && !IsWordChar(c) )
			break;  /* һ�����ʽ��� */
	}
	tempword[len] = '\0';   /* �趨�ַ��������� */
	if( len>KEYLENGTH ){    /* ̫���ĵ��ʱ��ض� */
		tempword[KEYLENGTH] = '\0';
		len = KEYLENGTH;
	}
	strcpy(word, tempword);
	return len;		
}
