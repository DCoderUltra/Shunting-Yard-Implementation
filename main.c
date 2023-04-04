#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "global.c"
#include "structs.h"
#include "f_create.h"
#include "functions.h"

int command(char *s);

int main()
{
	int line=1;
	system("clear");
	while(1){
		char s[256];
		fprintf(stdout, "SYA(%d) > ", line++);
		fgets(s, 255, stdin);
		if(!command(s)) break;
	}
	system("clear");
	return 0;
}

int command(char *s){

	// List of comands bellow
	if(strcmp(s, "quit\n")==0) return 0;
	// End of commands

	double result;
	int precision = 5-1;
	// Here a numerical expression can also be seen as constant function
	QE * FUNCTION;
	init_q(&FUNCTION);
	FUNCTION = f_create(s);
	if (FUNCTION==NULL) return 1;
	double x = 0;
	result = function(&FUNCTION, x);
	printf("ans = %.*f\n",precision, result);
	return 1;
}

