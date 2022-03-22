bool CheckCycle( SetType VSet, Vertex V1, Vertex V2 )
{ /* �������V1��V2�ı��Ƿ������е���С�������Ӽ��й��ɻ�· */
	Vertex Root1, Root2;

	Root1 = Find( VSet, V1 ); /* �õ�V1��������ͨ������ */
	Root2 = Find( VSet, V2 ); /* �õ�V2��������ͨ������ */

	if( Root1==Root2 ) /* ��V1��V2�Ѿ���ͨ����ñ߲���Ҫ */
		return false;
	else { /* ����ñ߿��Ա��ռ���ͬʱ��V1��V2����ͬһ��ͨ�� */
		Union( VSet, Root1, Root2 );
		return true;
	}
}
