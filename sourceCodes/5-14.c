#define MAXWORDLEN 80 /* 所有单词最大长度 */

int GetAWord( FILE *fp, ElementType word )
{
	char tempword[MAXWORDLEN+1], c;
	int len = 0; /* 单词长度 */

	c = fgetc(fp);
	while( !feof(fp) ){
		if( IsWordChar(c) )  /* 如果是合法的单词字符 */
			tempword[len++] = c;
		c = fgetc(fp);
		/* 跳过单词前的非法字符，或以非法字符结束一个单词*/
		if( len && !IsWordChar(c) )
			break;  /* 一个单词结束 */
	}
	tempword[len] = '\0';   /* 设定字符串结束符 */
	if( len>KEYLENGTH ){    /* 太长的单词被截断 */
		tempword[KEYLENGTH] = '\0';
		len = KEYLENGTH;
	}
	strcpy(word, tempword);
	return len;		
}
