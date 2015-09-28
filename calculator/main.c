/*
Main program of calculator example.
Simply invoke the parser generated by bison, and then display the output.
*/

#include <stdio.h>
#include "expr.h"

/* Clunky: Declare the parse function generated from parser.bison */
extern int yyparse();

/* Clunky: Declare the result of the parser from parser.bison */
extern struct expr * parser_result;

int main( int argc, char *argv[] )
{
	printf("CSE 40243 Expression Parser\n");
	printf("Enter an infix expression using the operators +-*/() ending with ;\n\n");

	if(yyparse()==0) {
		printf("parse successful: ");
		expr_print(parser_result);
		printf("\n");
		printf("evaluates to: %lg\n",expr_evaluate(parser_result));
		return 0;
	} else {
		printf("parse failed!\n");
		return 1;
	}
}

