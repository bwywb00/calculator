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
				// ��ȣ�� �ƴ� �Ϲ� �������� ���
				// ������ �����ڸ� �����ϴ� ���ÿ� �����Ͱ� �ִµ�
				// �� �����Ͱ� ���� �����Ϸ��� �����ͺ��� �켱������ ���ų� ���ٸ� ������ �迭�� �����Ѵ�
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