#include <stdio.h>

#include "global.c"
#include "structs.h"
#include "functions.h"

char *opers= "+-*/^()";
enum Association {a_none=0, a_right=1, a_left=2};

// Shunting Yard Alghoritm implementation
void alg_sya(QE ** PQE, int n_toks)
{
	ST *PES;
	init(&PES);

	int i=0;
	while(i<n_toks){
		// NUMBERS
		if(first(*PQE).prec==0){
			enqueue(PQE, first(*PQE));
			dequeue(PQE);
			i++;
		}
		else if(first(*PQE).prec==6){
			if(is_function(first(*PQE).string)){
				add(&PES, first(*PQE));
				dequeue(PQE);
			}
			else{
				enqueue(PQE,first(*PQE));
				dequeue(PQE);
			}
			i++;
		}
		else if(first(*PQE).prec==4){
			add(&PES, first(*PQE));
			dequeue(PQE); i++;
		}
		else if(first(*PQE).prec==5){
			dequeue(PQE); i++;
			while(top(PES).prec!=4){
				enqueue(PQE, top(PES));
				pop(&PES);
			}
			pop(&PES);
		}
		else if(first(*PQE).prec>0 && first(*PQE).prec<4){
			if(empty(PES) || first(*PQE).prec>top(PES).prec || top(PES).prec == 4){
				add(&PES, first(*PQE));
				dequeue(PQE); i++;
			}
			else{
				enqueue(PQE, top(PES));
				pop(&PES);
			}
		}
	}
	while(!empty(PES)){
		enqueue(PQE, top(PES));
		pop(&PES);
	}
}

