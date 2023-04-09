#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "global.c"
#include "structs.h"
#include "functions.h"
#include "action.h"

char * oper_l = "+-*/^()";

int rpn_calculator(QE ** FUNCTION_L, QE ** FUNCTION_T, double *res, double x){

	// Intialize Stack
	ST * CALCULATOR;
	init(&CALCULATOR);

	*res=0;
	int i=0,  n_toks=0;
	double a=0, b=0, arg=0;
	count_q(*FUNCTION_L, &n_toks);

	while(i<n_toks){
		// NUMBER
		if(first(*FUNCTION_L).prec==0){
			enqueue(FUNCTION_L, FUNCTION_T, first(*FUNCTION_L));
			double val = strtod(first(*FUNCTION_L).string, NULL);
			TOKEN t; t.prec=0; t.val = val;
			add(&CALCULATOR, t);
			dequeue(FUNCTION_L); i++;
		}
		// FUNCTION OR UNKNOWN
		else if(first(*FUNCTION_L).prec==6){
			if(is_function(first(*FUNCTION_L).string)){
				enqueue(FUNCTION_L, FUNCTION_T, first(*FUNCTION_L));
				arg = top(CALCULATOR).val;
				if(action(first(*FUNCTION_L).string,res,0,0,arg)==-1)
					return -1;
				TOKEN t; t.prec=0; t.val = *res;
				pop(&CALCULATOR);
				add(&CALCULATOR, t);
				dequeue(FUNCTION_L); i++;
			}
			else{
				enqueue(FUNCTION_L, FUNCTION_T, first(*FUNCTION_L));
				TOKEN t; t.prec=0; t.val = x;
				add(&CALCULATOR, t);
				dequeue(FUNCTION_L); i++;
			}
		}
		// OPERATOR
		else{
			enqueue(FUNCTION_L, FUNCTION_T, first(*FUNCTION_L));
			b = top(CALCULATOR).val; pop(&CALCULATOR);
			a = top(CALCULATOR).val; pop(&CALCULATOR);
			if(action(first(*FUNCTION_L).string, res, a, b, 0)==-1)
				return -1;
			TOKEN t; t.prec=0; t.val = *res;
			add(&CALCULATOR, t);
			dequeue(FUNCTION_L); i++;
		}
	}
	*res = top(CALCULATOR).val;
	free(CALCULATOR);
	return 0;
}

