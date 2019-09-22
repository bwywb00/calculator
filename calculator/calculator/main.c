#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayBaseStack.h"

int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
	{
		return 1;
	}
	else if (op1Prec < op2Prec)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void ConveToRPNExp(char exp[])
{
	Stack stack;

	int expLen = strlen(exp);
	// +1�� ���ִ� ������ �迭�� �������� �׻� '\0'
	char* convExp = (char*)malloc(expLen + 1);

	if (convExp != NULL)
	{
		memset(convExp, 0, sizeof(char) * (expLen + 1));
	}

	StackInit(&stack);

	int idx = 0;
	char tok, popOp;

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok);
				break;

			case ')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '*':
			case '/':
			case '+':
			case '-':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
				{
					// ���ÿ� ���𰡰� ����ְ� �켱������ ���ߴµ�
					// ���� �� ���� �����ڰ� tok���� �켱������ ���ų� ������
					// ������ convExp�� �־��
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);

}

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);

	StackInit(&stack);

	char tok, op1, op2;

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		
		if (isdigit(tok))
		{
			SPush(&stack, tok-'0');
		}
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);

			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}

		}

	}
	return SPop(&stack);

}

int main(void)
{

	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConveToRPNExp(exp1);
	ConveToRPNExp(exp2);
	ConveToRPNExp(exp3);

	printf("%d \n", EvalRPNExp(exp1)); // 7
	printf("%d \n", EvalRPNExp(exp2)); // 9
	printf("%d \n", EvalRPNExp(exp3)); // 6

	return 0;
}