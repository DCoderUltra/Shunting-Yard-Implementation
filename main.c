#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256

// Includes all needed structs needed by the headers
#include "structs.c"

#include "input.h"
#include "tok_functions.h"
#include "stack.h"
#include "queue.h"
#include "sya.h"
#include "rpn_calc.h"
#include "replace.h"
#include "action.h"

int main(){

	// Stack initalization
	ST *PES;
	init(&PES);

	// Queue initialization
	QE * PQE;
	init_q(&PQE);

	// Other variables initialization
	int n_tok=0;
	float x0;
	char res[SIZE], *s;
	printf("Introduza uma expressão: ");
	s = input(stdin,10);

	printf("Introduza x: ");
	scanf("%f", &x0);
	char *x0_string = (char *) malloc((sizeof(x0)+1)*sizeof(char));
	sprintf(x0_string, "%f", x0);

	// Funtion to be developed that would regularize any input that check if it's a valid one.
	//s = regular(s);

	// Function to determine the number of tokens present
	n_tok = tok_count(s);

	// List of tokens in Traditional Notation
	TOKEN * list = malloc(sizeof(TOKEN)*(n_tok+1));


	// Functions to get RPN)

	// Function  to convert the input to tokens
	list = creation(list, s, n_tok);

	// Shunting Yard Alghoritm implementation
	alg_sya(PES, list, n_tok, &PQE);

	// Output:
	printf("Reverse Polish Notation: ");
	list_q(PQE);
	putchar('\n');

	// Calculate RPN
	strcpy(res, rpn_calculator(PES, &PQE, n_tok, x0_string));
	puts(res);


//	free(list);

}

