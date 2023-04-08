#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SEP ' '
#define SIZE 256

#include "global.c"
#include "structs.h"

// Association definition
enum Association {A_NONE=0, A_RIGHT=1, A_LEFT=2};

// Token operators and functions
TOKEN oper[] = {
		{"NUMBERS", A_NONE, 0},
		{"FUNCTIONS/UNKNOWNS", A_RIGHT, 6},
		{")", A_NONE, 5},
		{"(", A_NONE, 4},
		{"^", A_RIGHT, 3},
		{"/", A_LEFT, 2},
		{"*", A_LEFT, 2},
		{"-", A_LEFT, 1},
		{"+", A_LEFT, 1},
		{"END", A_NONE, -1}
};

TOKEN * creation(TOKEN *list, char *s, int n_tok)
{
	int l_pos=0, k=0;
	while(l_pos<n_tok){
		char tmp[50]="\0";
		while(s[k]!=SEP && s[k]!='\0'){
			char ch[]=" ";
			ch[0]=s[k];
			strcat(tmp,ch);
			k++;
		}
		k++;
		strcpy(list[l_pos].string, tmp);
		if(isdigit(tmp[0])){
			list[l_pos].assoc=oper[0].assoc;
			list[l_pos].prec=oper[0].prec;
		}
		else if(isalpha(tmp[0])){
			list[l_pos].assoc=oper[1].assoc;
			list[l_pos].prec=oper[1].prec;
		}
		else{
			for(int i=2; oper[i].prec!=-1; i++){
				if(strcmp(tmp,oper[i].string)==0){
					list[l_pos].assoc=oper[i].assoc;
					list[l_pos].prec=oper[i].prec;
					break;
				}
			}
		}
		l_pos++;
	}

	return list;
}

void enqueue_list(TOKEN * list, int n_toks, QE ** lead, QE ** tail){
	for(int i=0; i<n_toks; i++)
		enqueue(lead, tail, list[i]);
}

int verify_functions(TOKEN * list, int n_toks){
	char func[15];
	FILE *fp = fopen("functions.txt", "r");
	for(int i=0; i<n_toks; i++){
		if(list[i].prec==6)
			while(fscanf(fp, "%s", func)!=EOF){
				if(strcmp(list[i].string, func)==0){
					if(list[i+1].string[0]!='('){
						printf("Bad use of function %s -> Try %s(argument)\nExamples: sin(5), cos(4-3), exp(-4^2) ...\n", list[i].string, list[i].string);
					fclose(fp);
					return -1;
					}
					break;
				}
			}
	}
	fclose(fp);
	return 0;
}

