int main()
{
	FILE *fp;
	HashTable H; /* 须改编代码5.6，结点增加计数器Count */
	ElementType word;
	int TableSize = 100; /* 散列表的估计大小，可以根据应用更改 */
	int length, wordcount = 0;
	char document[30] = "HarryPotter.txt"; /* 要被统计词频的文件名 */

	H = CreateTable( TableSize ); /* 用代码5.7建立散列表 */
	if(( fp = fopen(document, "r" )) == NULL)
		printf("无法打开文件！\n" );
                   	
	while( !feof(fp) ){
		length = GetAWord( fp, word ); /* 读取一个单词 */
		if( length>3 ){ /* 只考虑长度大于3个字符的单词 */
			wordcount++;
			InsertAndCount( H, word ); /* 改编代码5.9，统计word出现次数 */
		}
	}
	fclose( fp );

	printf("该文档共出现 %d 个有效单词", wordcount);
	Show( H, 10.0/100 );  /* 显示词频前10%的所有单词 */
	DestroyTable( H );    /* 用代码5.10销毁散列表 */
	return 0;
}
