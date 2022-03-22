AVLTree SingleLeftRotation ( AVLTree A )
{ /* 注意：A必须有一个左子结点B */
  /* 将A与B做如图4.35所示的左单旋，更新A与B的高度，返回新的根结点B */     

	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
 
	return B;
}
