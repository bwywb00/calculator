
int getOpPrec(char op)
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

int WhichOpPrec(char op1, char op2)
{
	if (op1 > op2)
	{
		return 1;
	}
	else if (op1 < op2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}