#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// Token types are globally defined in Common.h so that 
// they can be used in both yylexDC.cpp and main.cpp
enum TOKEN { TOK_EOF =0, TOK_INT, TOK_IDENTIFIER};
// Only in yylexDC.cpp, we need to define the states of the DFA
enum State { S0, STATE_INT, STATE_IDENTIFIER, STOP};
int yylex();
// Move definitions to Common.cpp to avoid multiple definition errors
extern FILE* f;
extern char yytext[64];

#endif
