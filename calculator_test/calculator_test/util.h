#pragma once

/* 연산자의 연산순위를 반환하는 함수	*/
/* 클수록 연산순위가 높다				*/
int getOpPrec(char op);

/* 두 연산자의 연산순위를 비교하는 함수 */
int WhichOpPrec(char op1, char op2);