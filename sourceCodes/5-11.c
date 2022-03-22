int main()
{
	FILE *fp;
	HashTable H; /* ��ı����5.6��������Ӽ�����Count */
	ElementType word;
	int TableSize = 100; /* ɢ�б�Ĺ��ƴ�С�����Ը���Ӧ�ø��� */
	int length, wordcount = 0;
	char document[30] = "HarryPotter.txt"; /* Ҫ��ͳ�ƴ�Ƶ���ļ��� */

	H = CreateTable( TableSize ); /* �ô���5.7����ɢ�б� */
	if(( fp = fopen(document, "r" )) == NULL)
		printf("�޷����ļ���\n" );
                   	
	while( !feof(fp) ){
		length = GetAWord( fp, word ); /* ��ȡһ������ */
		if( length>3 ){ /* ֻ���ǳ��ȴ���3���ַ��ĵ��� */
			wordcount++;
			InsertAndCount( H, word ); /* �ı����5.9��ͳ��word���ִ��� */
		}
	}
	fclose( fp );

	printf("���ĵ������� %d ����Ч����", wordcount);
	Show( H, 10.0/100 );  /* ��ʾ��Ƶǰ10%�����е��� */
	DestroyTable( H );    /* �ô���5.10����ɢ�б� */
	return 0;
}
