#pragma once

#include <stdlib.h>

#define TRUE				1
#define FALSE				0
#define MAX_STACK_SIZE		100

typedef struct _array_stack
{
	char stack_buff[MAX_STACK_SIZE];
	int top_Index;
} ArrayStack;

typedef struct _int_array_stack
{
	int stack_buff[MAX_STACK_SIZE];
	int top_Index;
} Int_ArrayStack;

typedef struct _char_p_array_stack
{
	char* stack_buff[MAX_STACK_SIZE];
	int top_Index;
} Char_P_ArrayStack;

typedef ArrayStack Stack;
typedef Int_ArrayStack Int_Stack;
typedef Char_P_ArrayStack Char_P_Stack;
typedef int Data;

/* char stack */
void Init_Stack(Stack* pstack);
int Is_stack_Empty(Stack* pstack);

Data Pop_S(Stack* pstack);
void Push_S(Stack* pstack, Data data);
Data Peek_s(Stack* pstack);

/* int stack */
void Init_Int_Stack(Int_Stack* pstack);
int Is_Int_stack_Empty(Int_Stack* pstack);

Data Pop_Int_S(Int_Stack* pstack);
void Push_Int_S(Int_Stack* pstack, Data data);
Data Peek_Int_s(Int_Stack* pstack);

/* char pointer stack */
void Init_Char_P_Stack(Char_P_Stack* pstack);
int Is_Char_P_Stack_Empty(Char_P_Stack* pstack);

char * Pop_Char_P_S(Char_P_Stack* pstack);
void Push_Char_P_S(Char_P_Stack* pstack, char* data);
char * Peek_Char_P_S(Char_P_Stack* pstack);