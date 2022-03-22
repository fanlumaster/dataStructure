int Hash( const char *Key, int TableSize )
{   
    unsigned int H = 0;     /* 散列函数值，初始化为0 */

    while ( *Key != '\0' )  /* 位移映射 */
        H = (H<<5) + *Key++;

    return H%TableSize;
}
