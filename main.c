#include <stdio.h>
#include <stdlib.h>
#include "global.c"
#include "structs.h"
#include "f_create.h"
#include "functions.h"

int main()
{
	double result;
	int precision = 20;

	// Here a numerical expression can also be seen as constant function
	QE * FUNCTION;
	init_q(&FUNCTION);

	while(1){
		system("clear");
		char s[256];
		fprintf(stdout, "Introduce a Numerical Expression: ");
		fgets(s, 255, stdin);
		FUNCTION = f_create(s);
		double x = 0;
		result = function(&FUNCTION, x);
		printf("Resultado: %.*f\n",precision, result);
		getchar();
	}
	return 0;
}

