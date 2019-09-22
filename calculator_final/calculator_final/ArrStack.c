#include <stdio.h>
#include "ArrStack.h"

//char Stack

void Init_Stack(Stack* pstack)
{
	pstack->top_Index = -1;
}

int Is_stack_Empty(Stack* pstack)
{
	if (pstack->top_Index == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Data Pop_S(Stack* pstack)
{
	if (Is_stack_Empty(pstack))
	{
		printf("Stack memory error\n");
		exit(-1);
	}

	int temp = pstack->top_Index;
	pstack->top_Index -= 1;

	return pstack->stack_buff[temp];
}

void Push_S(Stack* pstack, Data data)
{
	pstack->top_Index += 1;
	pstack->stack_buff[pstack->top_Index] = data;
}

Data Peek_s(Stack* pstack)
{
	return pstack->stack_buff[pstack->top_Index];
}

// Int Stack

void Init_Int_Stack(Int_Stack* pstack)
{
	pstack->top_Index = -1;
}

int Is_Int_stack_Empty(Int_Stack* pstack)
{
	if (pstack->top_Index == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Data Pop_Int_S(Int_Stack* pstack)
{
	if (Is_Int_stack_Empty(pstack))
	{
		printf("Stack memory error\n");
		exit(-1);
	}

	int temp = pstack->top_Index;
	pstack->top_Index -= 1;

	return pstack->stack_buff[temp];
}

void Push_Int_S(Int_Stack* pstack, Data data)
{
	pstack->top_Index += 1;
	pstack->stack_buff[pstack->top_Index] = data;
}

Data Peek_Int_s(Int_Stack* pstack)
{
	return pstack->stack_buff[pstack->top_Index];
}

// char * stack
void Init_Char_P_Stack(Char_P_Stack* pstack)
{
	pstack->top_Index = -1;
}

int Is_Char_P_Stack_Empty(Char_P_Stack* pstack)
{
	if (pstack->top_Index == -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

char* Pop_Char_P_S(Char_P_Stack* pstack)
{
	if (Is_Char_P_Stack_Empty(pstack))
	{
		printf("Stack memory error\n");
		exit(-1);
	}

	int temp = pstack->top_Index;
	pstack->top_Index -= 1;

	return pstack->stack_buff[temp];
}

void Push_Char_P_S(Char_P_Stack* pstack, char *data)
{
	pstack->top_Index += 1;
	pstack->stack_buff[pstack->top_Index] = data;
}

char* Peek_Char_P_S(Char_P_Stack* pstack)
{
	return pstack->stack_buff[pstack->top_Index];
}