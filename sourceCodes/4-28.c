void Union( SetType S, SetName Root1, SetName Root2 )
{ /* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
	/* ��֤С���ϲ���󼯺� */
	if ( S[Root2] < S[Root1] ) { /* �������2�Ƚϴ� */
		S[Root2] += S[Root1];	 /* ����1���뼯��2  */
		S[Root1] = Root2;
	}
	else {						 /* �������1�Ƚϴ� */
		S[Root1] += S[Root2];	 /* ����2���뼯��1  */
		S[Root2] = Root1;
	}
}
