AVLTree DoubleLeftRightRotation ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
  /* ��A��B��C����ͼ4.38��ʾ�����ε����������µĸ����C */
	
	/* ��B��C���ҵ�����C������ */
	A->Left = SingleRightRotation(A->Left);
	/* ��A��C��������C������ */
	return SingleLeftRotation(A);
}
