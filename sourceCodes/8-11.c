int Kruskal( LGraph Graph, LGraph MST )
{ /* ����С����������Ϊ�ڽӱ�洢��ͼMST��������СȨ�غ� */
	WeightType TotalWeight;
    int ECount, NextEdge;
	SetType VSet; /* �������� */
	Edge ESet;    /* ������ */

	InitializeVSet( VSet, Graph->Nv ); /* ��ʼ�����㲢�鼯 */
	ESet = (Edge)malloc( sizeof(struct ENode)*Graph->Ne );
	InitializeESet( Graph, ESet ); /* ��ʼ���ߵ���С�� */
    /* �����������ж��㵫û�бߵ�ͼ��ע�����ڽӱ�汾 */
    MST = CreateGraph(Graph->Nv);
    TotalWeight = 0; /* ��ʼ��Ȩ�غ�     */
    ECount = 0;      /* ��ʼ����¼�ı��� */

	NextEdge = Graph->Ne; /* ԭʼ�߼��Ĺ�ģ */
	while ( ECount < Graph->Nv-1 ) {  /* ���ռ��ı߲����Թ�����ʱ */
		NextEdge = GetEdge( ESet, NextEdge ); /* �ӱ߼��еõ���С�ߵ�λ�� */
		if (NextEdge < 0) /* �߼��ѿ� */
			break;
        /* ����ñߵļ��벻���ɻ�·�������˽�㲻����ͬһ��ͨ�� */
		if ( CheckCycle( VSet, ESet[NextEdge].V1, ESet[NextEdge].V2 )==true ) {
            /* ���ñ߲���MST */
            InsertEdge( MST, ESet+NextEdge );
			TotalWeight += ESet[NextEdge].Weight; /* �ۼ�Ȩ�� */
			ECount++; /* �������б�����1 */
		}
	}
	if ( ECount < Graph->Nv-1 )
		TotalWeight = -1; /* ���ô����ǣ���ʾ������������ */

	return TotalWeight;
}
