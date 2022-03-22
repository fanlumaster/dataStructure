void ShellSort( ElementType A[], int N )
{ /* ϣ������ - ��Sedgewick�������� */
     int Si, D, P, i;
     ElementType Tmp;
     /* ����ֻ�г�һС�������� */
     int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
     
     for ( Si=0; Sedgewick[Si]>=N; Si++ ) 
         ; /* ��ʼ������Sedgewick[Si]���ܳ����������г��� */

     for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
         for ( P=D; P<N; P++ ) { /* ��������*/
             Tmp = A[P];
             for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
                 A[i] = A[i-D];
             A[i] = Tmp;
         }
}
