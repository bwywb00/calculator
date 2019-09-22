#include "EvalRNPExp.h"

//	case 1
//		12+3- -> +앞의 두 숫자 pop 후 연산 후 다시 push, -앞의 두 숫자 pop후 연산 후 다시 push
//	return value -> int

int EvalRNPExp(char exp[])
{
	Int_Stack stack;
	int expLen = strlen(exp);
	
	Init_Int_Stack(&stack);
	char tok, op1,op2;

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			Push_Int_S(&stack, tok-'0');
		}
		else
		{
			switch (tok)
			{
			case '+':
				op2 = Pop_Int_S(&stack);
				op1 = Pop_Int_S(&stack);

				Push_Int_S(&stack, op1 + op2);
				break;
			case '-':
				op2 = Pop_Int_S(&stack);
				op1 = Pop_Int_S(&stack);

				Push_Int_S(&stack, op1 - op2);
				break;
			case '*':
				op2 = Pop_Int_S(&stack);
				op1 = Pop_Int_S(&stack);

				Push_Int_S(&stack, op1 * op2);
				break;
			case '/':
				op2 = Pop_Int_S(&stack);
				op1 = Pop_Int_S(&stack);

				Push_Int_S(&stack, op1 / op2);
				break;
			}
		}
	}

	return Pop_Int_S(&stack);

}

