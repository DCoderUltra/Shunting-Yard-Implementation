#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_prep.h"
#include "global.c"
#include "structs.h"
#include "f_create.h"
#include "functions.h"
#define SIZE 256
#define wipe system("clear"); // Change if you're in Windows to cls

int command(char *s, double result, int precision, QE ** FUNCTION_L, QE ** FUNCTION_T);

int main(){
	double result=0;
	int precision = 5, line = 1;
	char * s = (char *) malloc(sizeof(char)*SIZE);

	QE * FUNCTION_L; init_queue(&FUNCTION_L);
	QE * FUNCTION_T; init_queue(&FUNCTION_T);

	// Main Loop
	wipe;
	while(1){
		while(!empty_queue(FUNCTION_L))
			dequeue(&FUNCTION_L);
		memset(s, '\0', SIZE);
		fprintf(stdout, "SYA(%d) > ", line);
		fgets(s, 255, stdin); if(s[0]=='\n') continue;
		line++; s[strlen(s)-1]='\0'; // Removes '\n'
		if(command(s, result, precision, &FUNCTION_L, &FUNCTION_T)==0) break;
	}
	wipe;
	free(s);
	return 0;
}

int command(char *s, double result, int precision, QE ** FUNCTION_L, QE ** FUNCTION_T){
	// List of comands bellow
	if(strcmp(s, "quit")==0) return 0;
	if(strcmp(s, "clear")==0) {wipe; return 1;}
	if(strcmp(s, "help")==0) {system("cat README.md | less"); return 1;}
	// End of commands
	if(f_create(s, FUNCTION_L, FUNCTION_T)==-1) return -1;
	if(function(FUNCTION_L, FUNCTION_T, &result, 0)==-1) return -1;
	printf("ans = %.*f\n",precision, result);
	return 1;
}

