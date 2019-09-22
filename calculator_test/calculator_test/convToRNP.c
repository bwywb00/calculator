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

//	case 1
//	111+222 -> "111" "222" "+"
char **convToRNP_P(char exp[])
{
	Stack stack;
	Init_Stack(&stack);
	char tok, popOp;
	int index = 0, counter = 0, exp_parser_num = 0, exp_parser_index = 0;

	int expLen = strlen(exp);

	for (int i = 0; i < expLen; i++)
	{
		if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))
		{
			counter++;
		}
	}

	exp_parser_num = 2 * counter + 1;

	char** exp_parser = (char**)malloc(sizeof(char *)* exp_parser_num);
	
	if (exp_parser != NULL)
	{
		for (int i = 0; i < exp_parser_num; i++)
		{
			exp_parser[i] = (char*)malloc(sizeof(char) * 10);
			memset(exp_parser[i], 0, sizeof(char) * 10);
		}
	}

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		
		if (isdigit(tok))
		{
			exp_parser[exp_parser_index][index++] = tok;
		}
		else
		{
			index = 0;

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
					exp_parser_index += 1;
					exp_parser[exp_parser_index][0] = popOp;
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
					exp_parser_index += 1;
					exp_parser[exp_parser_index][0] = Pop_S(&stack);
				}
				Push_S(&stack, tok);
				break;
			}
			exp_parser_index += 1;
		}

	}

	while (!Is_stack_Empty(&stack))
	{
		exp_parser_index += 1;
		exp_parser[exp_parser_index][0] = Pop_S(&stack);
	}

	return exp_parser;


	//Init_Stack(&stack);
	//int index_conv = 0;
	//char tok, popOp;

	//char* convExp = (char*)malloc((expLen + 1));
	//if (convExp != NULL)
	//{
	//	memset(convExp, 0, sizeof(char) * (expLen + 1));
	//}

	//for (int i = 0; i < expLen; i++)
	//{
	//	tok = exp[i];

	//	if (isdigit(tok))
	//	{
	//		convExp[index_conv++] = tok;
	//	}
	//	else
	//	{
	//		switch (tok)
	//		{
	//		case '(':
	//			Push_S(&stack, tok);
	//			break;
	//		case ')':
	//			while (1)
	//			{
	//				popOp = Pop_S(&stack);
	//				if (popOp == '(')
	//					break;
	//				convExp[index_conv++] = popOp;
	//			}
	//			break;
	//		case '+':
	//		case '-':
	//		case '*':
	//		case '/':
	//			// 괄호가 아닌 일반 연산자의 경우
	//			// 스택이 연산자를 저장하는 스택에 데이터가 있는데
	//			// 그 데이터가 새로 저장하려는 데이터보다 우선순위가 높거나 같다면 꺼내서 배열에 저장한다
	//			while (!Is_stack_Empty(&stack) && WhichOpPrec(Peek_s(&stack), tok) >= 0)
	//			{
	//				convExp[index_conv++] = Pop_S(&stack);
	//			}
	//			Push_S(&stack, tok);
	//			break;
	//		}
	//	}
	//}

	//while (!Is_stack_Empty(&stack))
	//	convExp[index_conv++] = Pop_S(&stack);

	//strcpy(exp, convExp);
	//free(convExp);
}