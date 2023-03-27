#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "structs.c"
#include "rpn_calc.h"
#include "stack.h"
#include "queue.h"
#include "action.h"
#include "func_lib.c"

char * oper_l = "+-*/^()";

char * rpn_calculator(ST *PES, QE ** PQE , int n_tok, char * x0_string)
{
	double a,b, arg;
	double res;
	int restart;

	// Intialize Stack
	init(&PES);


	while((*PQE)!=NULL){

		restart=0;
		// Check if it is a funtion
		for(int i = 0; functions[i][0]!='\0'; i++)
		{
			if(strcmp(functions[i], first(*PQE).string)==0)
			{
				// Function arg
				if(strcmp(top(PES).string, "x")==0)
					arg = strtod(x0_string, NULL);
				else
					arg = strtod(top(PES).string, NULL);
				pop(&PES);

				res = action(PQE, 0, 0, arg);

				char str[256]={'\0'};
				snprintf(&str[0], 256, "%f", res);
				TOKEN temp_f;
				strcpy(temp_f.string, str);
				temp_f.assoc=0;
				temp_f.prec=0;
				add(&PES, temp_f);
				dequeue(PQE);
				restart = 1;
				break;
			}
		}
		if(restart==1) continue;

		// It's an operator
		if(strchr(oper_l,first(*PQE).string[0]) && first(*PQE).string[1]=='\0'){

			// Last num
			if(strcmp(top(PES).string, "x")==0)
				b = strtod(x0_string, NULL);
			else
				b = strtod(top(PES).string, NULL);
			pop(&PES);

			// Fist num
			if(strcmp(top(PES).string, "x")==0)
				a = strtod(x0_string, NULL);
			else
				a = strtod(top(PES).string, NULL);
			pop(&PES);

			res = action(PQE, a, b, 0);

			char str[256];
			snprintf(&str[0], 256, "%f", res);
			TOKEN temp;
			strcpy(temp.string, str);
			temp.assoc=0;
			temp.prec=0;
			add(&PES, temp);
		}
		// It's a num
		else{
			add(&PES, (*PQE)->t);
		}
		dequeue(PQE);
	}

	return top(PES).string;
}

