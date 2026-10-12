#include <locale>

#include "Common.h" 

int yylex() {
	static int ch = -2;
	int length = 0;
	int state = S0;
	int next;

	if (ch == -2) {
		ch = fgetc(f);
	}

	while (ch != EOF) {
		next = STOP;
		switch (state) {
		case S0:
			if (isdigit(ch)) {
				next = STATE_INT;
			}
			else if (isalpha(ch)) {
				next = STATE_IDENTIFIER;
			}
			else {
				next = S0;
			}
			break;
		case STATE_INT:
			if (isdigit(ch)) {
				next = STATE_INT;
			}
			break;
		case STATE_IDENTIFIER:
			if (isalpha(ch) || isdigit(ch)) {
				next = STATE_IDENTIFIER;
			}
			break;
		}

		if (next == STOP) {
			break;
		}

		if (next != S0) {
			yytext[length++] = ch;
		}
		ch = fgetc(f);
		state = next;

	}
	yytext[length] = '\0';
	if (state == STATE_INT) {
		return TOK_INT;
	}
	else if (state == STATE_IDENTIFIER) {
		return TOK_IDENTIFIER;
	}
	else {
		return TOK_EOF;
	}	
}