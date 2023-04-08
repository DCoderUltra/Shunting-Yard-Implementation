#include<stdio.h>
#include<stdlib.h>
#include "str_prep.h"
#include "global.c"
#include "tok_functions.h"
#include "structs.h"
#include "alg_sya.h"


int f_create(char *s, QE ** FUNCTION_L, QE **FUNCTION_T){
	int n_toks;

	// String Preparation and Check
	remove_spaces(s); printf("NWS: %s\n", s);
	if(verify(s)==-1) return -1;
	regular(s); printf("PFN: %s\n",s);
	n_toks = count_toks(s);

	// List Tokens Creation
	TOKEN * list = malloc(sizeof(TOKEN)*(n_toks+1));
	list = creation(list, s, n_toks);
	if(verify_functions(list, n_toks)!=0) return -1;
	enqueue_list(list, n_toks, FUNCTION_L, FUNCTION_T);
	free(list);

	// Shunting Yard Alghoritm
	alg_sya(FUNCTION_L, FUNCTION_T, n_toks);
	printf("RPN: "); list_q(*FUNCTION_L); puts("\n");
	return 0;
}

