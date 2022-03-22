#define NotFound 0 /* �Ҳ����򷵻�0 */

Position BinarySearch( List Tbl, ElementType K )
{ /* ��˳��洢�ı�Tbl�в��ҹؼ���ΪK������Ԫ�� */
	Position left, right, mid;

    left = 1;          /* ��ʼ��߽� */
    right = Tbl->Last; /* ��ʼ�ұ߽� */
    while( left<=right )
    {
        mid = (left+right)/2;  /* �����м�Ԫ������ */
        if( K<Tbl->Data[mid] )      right = mid - 1; /* �����ұ߽� */
        else if( K>Tbl->Data[mid] ) left = mid + 1;  /* ������߽� */
        else return mid;   /* ���ҳɹ�����������Ԫ�ص��±� */
    }
    return NotFound;   /* ���ز��Ҳ��ɹ��ı�ʶ */
}
