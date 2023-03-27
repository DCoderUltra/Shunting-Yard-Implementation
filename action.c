#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "structs.c"
#include "queue.h"
#include "action.h"

// Switch case not used due to not being able to compare strings so I decided to
// compare using a lot... of if satements

double action(QE ** PQE, double a, double b, double arg)
{

	// Traditional Operators
	if(strcmp("^", first(*PQE).string)==0)
		return pow(a,b);
	if(strcmp("*", first(*PQE).string)==0)
		return a*b;
	if(strcmp("/", first(*PQE).string)==0)
		return a/b;
	if(strcmp("+", first(*PQE).string)==0)
		return a+b;
	if(strcmp("-", first(*PQE).string)==0)
		return a-b;

	// Function
	if(strcmp("sin", first(*PQE).string)==0)
		return sin(arg);
	if(strcmp("cos", first(*PQE).string)==0)
		return cos(arg);
	if(strcmp("tan", first(*PQE).string)==0)
		return tan(arg);
	if(strcmp("exp", first(*PQE).string)==0)
		return exp(arg);
	if(strcmp("log", first(*PQE).string)==0)
		return log(arg);

}

