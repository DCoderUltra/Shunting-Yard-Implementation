#include<stdlib.h>
#include<string.h>

#include "structs.c"
#include "tok_functions.h"

/*
enum Token_type{
	None, //Sentinel value
	Number,
	Add,
	Subtract,
	Multiply,
	Division,
	Exponent,
	Right_parenthesis,
	Left_parentesis,
//
//	List,
//	Vector,
//	Matrix,
//	Etc
//
}

struct Token_ap{
	Token_type token;
	enum assoc association;
	int precedence;
}

Token_ap[] = {
		{Left_parenthesis, A_NONE, 4},
		{Right_parenthesis, A_NONE, 4},
		{Exponent, A_RIGHT, 3},
		{Division, A_LEFT, 2},
		{Multiply, A_LEFT, 2},
		{Subtract, A_LEFT, 1},
		{Add, A_LEFT, 1},
		{Number, A_NONE, 0}
	}

//{Token type, function*}
struct Token_op[]{
		{Left_parenthesis, NULL},
		{Right_parenthesis, NULL},
		{Exponent, &pow},
		{Division, &div},
		{Multiply, &mul},
		{Subtract, &sub},
		{Add, &add},
		{Number, NULL},
		{None, NULL} //sentinel value
	}


struct Token{
	enum Token_type type;
	//number, function or anything else apropriate to current type
	void* data;
}
*/

// Operator String
char * s_oper = "+-*/^()";

// Token operators and functions
TOKEN oper[] = {
		{"sin", A_RIGHT, -1},
		{"cos", A_RIGHT, -1},
		{"tan", A_RIGHT, -1},
		{"exp", A_RIGHT, -1},
		{"log", A_RIGHT, -1}, // More functions could be added here, remember to also add them to  the file func_lib.c, and define what they do at action.c
		{")", A_NONE, 6},
		{"(", A_NONE, 5},
		{"^", A_RIGHT, 3},
		{"/", A_LEFT, 2},
		{"*", A_LEFT, 2},
		{"-", A_LEFT, 1},
		{"+", A_LEFT, 1},
		{"0", A_NONE, 0}
};

// Function to count the number of tokens
int tok_count(char *s){
	// Detect if the string it's not empy
	if(s[0]=='\0')
		return -1;
	// Keeps count of the tokens (i.e number of spaces + 1)
	int count=1;
	// Loop to count tokens
	for(int i=0; s[i+1]!='\0'; i++)
		if (s[i]==' ')
			count++;
	return count;
}

TOKEN * creation(TOKEN *list, char *s, int n_tok)
{
	int l_pos=0;
	char *s_copy = (char *) malloc(strlen(s)+1);
	char *tmp = s_copy;
	char *begin = s_copy;
	strcpy(s_copy, s);

	// Create Default TOKENS (i.e. all are numbers for now)
	while(*tmp!='\0'){
		if(*(tmp+1)=='\0')
		{
			strcpy(list[l_pos].string, begin);
			list[l_pos].assoc=A_NONE;
			list[l_pos].prec=0;
			break;
		}
		if(*tmp==' '){
			*tmp='\0';
			strcpy(list[l_pos].string, begin);
			list[l_pos].assoc=A_NONE;
			list[l_pos].prec=0;
			l_pos++;
			begin=tmp+1;
		}
		tmp++;
	}
	// Transform each token to what it really is
	for(int i=0, l_pos=0; list[i].string[0]!='\0'; i++){
		for(int j=0; strcmp(oper[j].string,"0");j++){
			if(!strcmp(list[i].string, oper[j].string)){
				strcpy(list[i].string, oper[j].string);
				list[i].assoc=oper[j].assoc;
				list[i].prec=oper[j].prec;
				break;
				}
			}
	}
	return list;
}

/*
//Function to remove extra spaces here!
char *regular(char *s)
{

	char *tmp = (char *) malloc(strlen(s)+1);
	for(int i=0, j=0; s[i]!='\0'; i++)
	{
		if(s[i]!=' ')
			tmp[j++]=s[i];
	}
	for(int j=0, i=0; tmp[j]!='\0'; j++)
	{
		s[i++]=tmp[j];
		if(strchr(s_oper, tmp[j+1]))
		{
			s[i++]=' ';

		}
		else
	}

	puts(tmp);
	return "1 + 1";

}
*/

