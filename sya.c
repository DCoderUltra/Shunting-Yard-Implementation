// Token definition
#include "structs.c"
#include "sya.h"
#include "tok_functions.h"
#include "stack.h"
#include "queue.h"


// Shunting Yard Alghoritm implementation

void alg_sya(ST * PES, TOKEN *t_list, int n_tok, QE ** PQE)
{

	for(int i=0; t_list[i].string[0]!='\0'; i++){
		/*if(t_list[i].prec==-1){
			add(&PES, t_list[i]);
			continue;
		}*/
		if(t_list[i].prec==5 || t_list[i].prec==6){
			if(t_list[i].prec==5)
				add(&PES, t_list[i]);
			if(t_list[i].prec==6){
				while(top(PES).string[0]!='('){
					enqueue(&(*PQE), top(PES));
					pop(&PES);
				}
				pop(&PES);
			}
		}
		else{
			// Number
			if(t_list[i].prec==0)
		 		enqueue(PQE, t_list[i]);
			// Not a Number
			else{
				// Stack is empty
				if(empty(PES))
					add(&PES, t_list[i]); // Add operator to the Stack
				// Stack is not empty
				else {
					if(t_list[i].assoc == A_RIGHT)
						add(&PES, t_list[i]);
					else{
						// Operator has bigger precende
						if(t_list[i].prec>top(PES).prec || top(PES).prec==5)
							add(&PES, t_list[i]);
						// Operator doesn't has bigger precedence
						else{
							while(1)
							{
		 						enqueue(&(*PQE), top(PES));
								pop(&PES);
							//	if((t_list[i].prec==top(PES).prec && t_list[i].assoc==A_LEFT) || t_list[i].prec > top(PES).prec || empty(PES)){
								if(t_list[i].prec > top(PES).prec || empty(PES)){
									add(&PES, t_list[i]);
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	while(!empty(PES)){
		enqueue(&(*PQE), top(PES));
		pop(&PES);
	}
}

