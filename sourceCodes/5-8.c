Position Find( HashTable H, ElementType Key )
{
    Position P;
    Index Pos;
    
    Pos = Hash( Key, H->TableSize ); /* ��ʼɢ��λ�� */
    P = H->Heads[Pos].Next; /* �Ӹ�����ĵ�1����㿪ʼ */
    /* ��δ����β������Keyδ�ҵ�ʱ */ 
    while( P && strcmp(P->Data, Key) )
        P = P->Next;

    return P; /* ��ʱP����ָ���ҵ��Ľ�㣬����ΪNULL */
}
