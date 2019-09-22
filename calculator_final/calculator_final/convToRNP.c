#include "convToRNP.h"

//	case 1
//		1+2-3 -> 12+3-
//		2*4-3 -> 42*3-
//	case 2
//		2+4*7 -> 247*+
//		6-3/3 -> 633/-
//	case 3
//		(3-1)*4 -> 31-4*
//		(4-3)/3+(5-3)*7 ->43-3/53-7*+

void convToRNP(char exp[])
{
	Stack stack;

	int expLen = strlen(exp);

	Init_Stack(&stack);
	int index_conv = 0;
	char tok, popOp;

	char* convExp = (char*)malloc((expLen + 1));
	if (convExp != NULL)
	{
		memset(convExp, 0, sizeof(char) * (expLen + 1));
	}

	for (int i = 0; i < expLen; i++) 
	{
		tok = exp[i];
		
		if (isdigit(tok))
		{
			convExp[index_conv++] = tok;
		}
		else
		{
			switch (tok)
			{
			case '(':
				Push_S(&stack, tok);
				break;
			case ')':
				while (1)
				{
					popOp = Pop_S(&stack);
					if (popOp == '(')
						break;
					convExp[index_conv++] = popOp;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				// 괄호가 아닌 일반 연산자의 경우
				// 스택이 연산자를 저장하는 스택에 데이터가 있는데
				// 그 데이터가 새로 저장하려는 데이터보다 우선순위가 높거나 같다면 꺼내서 배열에 저장한다
				while (!Is_stack_Empty(&stack) && WhichOpPrec(Peek_s(&stack), tok) >= 0)
				{
					convExp[index_conv++] = Pop_S(&stack);
				}
				Push_S(&stack, tok);
				break;
			}
		}
	}

	while (!Is_stack_Empty(&stack))
		convExp[index_conv++] = Pop_S(&stack);

	strcpy(exp, convExp);
	free(convExp);
}

void convToRNP_for_P(char exp[])
{

}