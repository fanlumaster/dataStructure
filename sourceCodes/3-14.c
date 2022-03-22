bool Push( Stack S, ElementType X, int Tag )
{ /* Tag作为区分两个堆栈的标志，取值为1和2 */
	if ( S->Top2-S->Top1 == 1) { /* 堆栈满 */
		printf("堆栈满\n");
		return false;
	}
	else {
		if ( Tag == 1 ) /* 对第一个堆栈操作 */
			S->Data[++(S->Top1)] = X;
		else              /* 对第二个堆栈操作 */
			S->Data[--(S->Top2)] = X;
		return true;
	}
}

ElementType Pop( Stack S, int Tag )
{ /* Tag作为区分两个堆栈的标志，取值为1和2 */
	if ( Tag == 1 ) { /* 对第一个堆栈操作 */
		if ( S->Top1 == -1 ) { /* 堆栈1空 */
			printf("堆栈1空\n");
			return ERROR;
		}
		else return S->Data[(S->Top1)--];
	}
	else { /* 对第二个堆栈操作 */
		if ( S->Top2 == S->MaxSize ) { /* 堆栈2空 */
			printf("堆栈2空\n");
			return ERROR;
		}
		else  return S->Data[(S->Top2)++];
	}
}
