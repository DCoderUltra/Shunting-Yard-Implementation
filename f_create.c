#include<stdio.h>
#include<stdlib.h>
#include "str_prep.h"
#include "global.c"
#include "tok_functions.h"
#include "structs.h"
#include "sya.h"

int f_create(char *s, QE ** FUNCTION){
	int n_toks;

	// String Preparation and Check
	remove_spaces(s); //printf("\nNWS: %s", s);
	if(verify(s)==-1) return -1;
	regular(s); //printf("\nPFN: %s",s);
	n_toks = count_toks(s);

	// List Tokens Creation
	TOKEN * list = malloc(sizeof(TOKEN)*(n_toks+1));
	list = creation(list, s, n_toks);
	if(verify_functions(list, n_toks)!=0) return -1;

	enqueue_list(list, n_toks, FUNCTION);
	// Shunting Yard Alghoritm
	alg_sya(FUNCTION, n_toks);
	//printf("\nRPN: "); list_q(*FUNCTION); puts("\n");
	return 0;

}

