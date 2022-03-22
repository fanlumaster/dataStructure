AVLTree SingleLeftRotation ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B */
  /* ��A��B����ͼ4.35��ʾ������������A��B�ĸ߶ȣ������µĸ����B */     

	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
 
	return B;
}
