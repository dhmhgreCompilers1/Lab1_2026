#include <stdio.h>
#include <stdlib.h>
#include "Common.h"


int main(int argc, char* argv[]) {
	
	//1. Ανοιγουμε κάποιο αρχειο ή από το πληκτρολόγιο αν δεν υπάρχει αρχείο
	if (argc == 2) {
		fopen_s(&f, argv[1], "r");
		if (f == NULL) {
			printf("Could not open file %s", argv[1]);
			exit(1);
		}
	}
	else if (argc > 2) {
		printf("Not appropriate number of arguments %s", argv[1]);
		exit(2);
	}
	else {
		f = stdin;
	}



	//2. Διαβαζουμε το αρχείο token προς token και το εμφανιζουμε στην οθονη
	// τον τυπο του token (π.χ. INDENTIFIER, INTEGER) και την τιμή του. 
	// Η ανάγνωση γίνεται μέχρι να φτάσουμε στο τέλος του αρχείου (EOF).
	int tokenID;
	while ((tokenID = yylex()) != EOF) {
		switch (tokenID) {
		case TOK_INT:
			printf("\nNUMBER: %s", yytext);
			break;

		case TOK_IDENTIFIER:
			printf("\nIDENTIFIER: %s", yytext);
			break;
		}
		printf("\n");
	}

	// Close file
	fclose(f);




		return 0;
}