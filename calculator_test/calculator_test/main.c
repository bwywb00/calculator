#include <stdio.h>
#include "convToRNP.h"
#include "EvalRNPExp.h"

int main(void)
{
	char** convExp = NULL;
	char exp1[] = "3*(22-10)";

	convExp = convToRNP_P(exp1);
	
	for (int i = 0; i < 5; i++)
	{
		printf("%s", convExp[i]);
	}


	return 0;
}