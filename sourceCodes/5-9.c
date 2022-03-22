bool Insert( HashTable H, ElementType Key )
{
    Position P, NewCell;
    Index Pos;
    
    P = Find( H, Key );
    if ( !P ) { /* �ؼ���δ�ҵ������Բ��� */
        NewCell = (Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        Pos = Hash( Key, H->TableSize ); /* ��ʼɢ��λ�� */
        /* ��NewCell����ΪH->Heads[Pos]����ĵ�1����� */
        NewCell->Next = H->Heads[Pos].Next;
        H->Heads[Pos].Next = NewCell; 
        return true;
    }
    else { /* �ؼ����Ѵ��� */
        printf("��ֵ�Ѵ���");
        return false;
    }
}
