#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Switch case not used due to not being able to compare strings so I decided to
// compare using a lot... of if satements

int action(char *s, double * res, double a, double b, double arg)
{

	// Traditional Operators
	if(strcmp("^", s)==0)
		*res = pow(a,b);
	else if(strcmp("*", s)==0)
		*res = a*b;
	else if(strcmp("/", s)==0)
		*res = a/b;
	else if(strcmp("+", s)==0)
		*res = a+b;
	else if(strcmp("-", s)==0)
		*res = a-b;

	// Function
	else if(strcmp("sin", s)==0)
		*res = sin(arg);
	else if(strcmp("cos", s)==0)
		*res = cos(arg);
	else if(strcmp("tan", s)==0)
		*res = tan(arg);
	else if(strcmp("exp", s)==0)
		*res = exp(arg);
	else if(strcmp("log", s)==0){
		if(arg<=0){
			printf("Error: value out of function %s(x) domain\n", s);
			return -1;
		}
		*res = log(arg);
	}
	else	return -1;

	return 0;

}

