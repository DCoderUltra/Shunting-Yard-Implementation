#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "global.c"
#include "structs.h"
#include "f_create.h"
#include "functions.h"
#define SIZE 256

int command(char *s, double result, int precision, QE ** FUNCTION);

int main()
{
	double result;
	int precision = 5;
	int line=1;
	char * s = (char *) malloc(sizeof(char)*SIZE);

	QE * FUNCTION;
	init_q(&FUNCTION);

	// Main Loop
	system("clear");
	while(1){
		dequeue_all(&FUNCTION);
		memset(s, '\0', SIZE);
		fprintf(stdout, "SYA(%d) > ", line);
		fgets(s, 255, stdin); if(s[0]=='\n') continue;
		line++; s[strlen(s)-1]='\0'; // Removes '\n'
		if(command(s, result, precision, &FUNCTION)==0) break;
	}
	system("clear");
	free(s);
	return 0;
}

int command(char *s, double result, int precision, QE ** FUNCTION){

	// List of comands bellow
	if(strcmp(s, "quit")==0) return 0;
	// End of commands

	if (f_create(s, FUNCTION)==-1) return -1;
	if (function(FUNCTION,&result, 0)==-1) return -1; // For variables f(x) change 0 for the number you want
	printf("ans = %.*f\n",precision, result);
	return 1;
}

