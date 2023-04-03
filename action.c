#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Switch case not used due to not being able to compare strings so I decided to
// compare using a lot... of if satements

double action(char *s, double a, double b, double arg)
{

	// Traditional Operators
	if(strcmp("^", s)==0)
		return pow(a,b);
	if(strcmp("*", s)==0)
		return a*b;
	if(strcmp("/", s)==0)
		return a/b;
	if(strcmp("+", s)==0)
		return a+b;
	if(strcmp("-", s)==0)
		return a-b;

	// Function
	if(strcmp("sin", s)==0)
		return sin(arg);
	if(strcmp("cos", s)==0)
		return cos(arg);
	if(strcmp("tan", s)==0)
		return tan(arg);
	if(strcmp("exp", s)==0)
		return exp(arg);
	if(strcmp("log", s)==0)
		if(arg<=0){
			printf("Error: value out o function %s(x) domain", s);
			exit(0);
		}
		return log(arg);

}

