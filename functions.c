#include <stdio.h>
#include <string.h>
#include "global.c"
#include "structs.h"
#include "rpn_calc.h"

int is_function(char *f_test){
	FILE *fp = fopen("functions.txt", "r");
	char f_read[256];
	while(fscanf(fp, "%s", f_read)!=EOF){
		if(strcmp(f_test,f_read)==0){
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

double function(QE ** FUNCTION, double x){
	return rpn_calculator(FUNCTION, x);
}

