#include <stdlib.h>
#include "global.c"
#include "structs.h"
#include "functions.h"

char *opers= "+-*/^()";
enum Association {a_none=0, a_right=1, a_left=2};

// Shunting Yard Alghoritm implementation
void alg_sya(QE ** FUNCTION_L, QE ** FUNCTION_T, int n_toks)
{
	ST * PES;
	init(&PES);

	int i=0;
	while(i<n_toks){
		if(first(*FUNCTION_L).prec==0){
			enqueue(FUNCTION_L, FUNCTION_T, first(*FUNCTION_L));
			dequeue(FUNCTION_L);
			i++;
		}
		else if(first(*FUNCTION_L).prec==6){
			if(is_function(first(*FUNCTION_L).string)){
				add(&PES, first(*FUNCTION_L));
				dequeue(FUNCTION_L);
			}
			else{
				enqueue(FUNCTION_L, FUNCTION_T,first(*FUNCTION_L));
				dequeue(FUNCTION_L);
			}
			i++;
		}
		else if(first(*FUNCTION_L).prec==4){
			add(&PES, first(*FUNCTION_L));
			dequeue(FUNCTION_L); i++;
		}
		else if(first(*FUNCTION_L).prec==5){
			dequeue(FUNCTION_L); i++;
			while(top(PES).prec!=4){
				enqueue(FUNCTION_L, FUNCTION_T, top(PES));
				pop(&PES);
			}
			pop(&PES);
		}
		else if(first(*FUNCTION_L).prec>0 && first(*FUNCTION_L).prec<4){
			if(empty(PES) || first(*FUNCTION_L).prec>top(PES).prec || top(PES).prec == 4){
				add(&PES, first(*FUNCTION_L));
				dequeue(FUNCTION_L); i++;
			}
			else{
				enqueue(FUNCTION_L, FUNCTION_T, top(PES));
				pop(&PES);
			}
		}
	}
	while(!empty(PES)){
		enqueue(FUNCTION_L, FUNCTION_T, top(PES));
		pop(&PES);
	}
}

