#include<stdio.h>
#include<stdlib.h>

#include "str_prep.h"
#include "global.c"
#include "tok_functions.h"
#include "structs.h"
#include "sya.h"

QE * f_create(char *s){
	int n_toks;

	// Queue initialization
	QE * PQE;
	init_q(&PQE);

	// String Preparation and Check
	remove_spaces(s); printf("NWS: ~%s~\n", s);
	verify(s);
	n_toks=regular(s); printf("PFN: ~%s~\n",s);

	// List Tokens Creation
	TOKEN * list = malloc(sizeof(TOKEN)*(n_toks+1));
	list = creation(list, s, n_toks);
	enqueue_list(list, n_toks, &PQE);

	// Shunting Yard Alghoritm implementation
	alg_sya(&PQE, n_toks);
	printf("RPN: ~"); list_q(PQE); puts("~\n");
	return PQE;
}

