#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "global.c"
#include "structs.h"
#include "functions.h"
#include "action.h"

char * oper_l = "+-*/^()";

double rpn_calculator(QE ** FUNCTION, double x){

	// Intialize Stack
	ST * CALCULATOR;
	init(&CALCULATOR);

	int i=0;
	int n_toks=0;
	count_q(*FUNCTION, &n_toks);

	double a=0, b=0, arg=0, res=0;

	while(i<n_toks){
		// NUMBER
		if(first(*FUNCTION).prec==0){
			enqueue(FUNCTION, first(*FUNCTION));
			double val = strtod(first(*FUNCTION).string, NULL);
			TOKEN t; t.prec=0; t.val = val;
			add(&CALCULATOR, t);
			dequeue(FUNCTION); i++;
		}
		// FUNCTION OR UNKNOWN
		else if(first(*FUNCTION).prec==6){
			if(is_function(first(*FUNCTION).string)){
				enqueue(FUNCTION, first(*FUNCTION));
				arg = top(CALCULATOR).val;
				res = action(first(*FUNCTION).string,0,0,arg);
				TOKEN t; t.prec=0; t.val = res;
				add(&CALCULATOR, t);
				dequeue(FUNCTION); i++;
			}
			else{
				enqueue(FUNCTION, first(*FUNCTION));
				TOKEN t; t.prec=0; t.val = x;
				add(&CALCULATOR, t);
				dequeue(FUNCTION); i++;
			}
		}
		// OPERATOR
		else{
			enqueue(FUNCTION, first(*FUNCTION));
			b = top(CALCULATOR).val; pop(&CALCULATOR);
			a = top(CALCULATOR).val; pop(&CALCULATOR);
			res = action(first(*FUNCTION).string, a, b, 0);
			TOKEN t; t.prec=0; t.val = res;
			add(&CALCULATOR, t);
			dequeue(FUNCTION); i++;
		}
	}

	return top(CALCULATOR).val;
}

