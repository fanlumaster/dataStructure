int Hash( const char *Key, int TableSize )
{   
    unsigned int H = 0;     /* ɢ�к���ֵ����ʼ��Ϊ0 */

    while ( *Key != '\0' )  /* λ��ӳ�� */
        H = (H<<5) + *Key++;

    return H%TableSize;
}
