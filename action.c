#include <stdio.h>
#include <string.h>
#include <math.h>

int action(char *s, double * res, double a, double b, double arg){
	// Traditional Operators
	if(strcmp("^", s)==0) 		*res = pow(a,b);
	else if(strcmp("*", s)==0)	*res = a*b;
	else if(strcmp("/", s)==0)	*res = a/b;
	else if(strcmp("+", s)==0)	*res = a+b;
	else if(strcmp("-", s)==0)	*res = a-b;
	// Function
	else if(strcmp("sin", s)==0)	*res = sin(arg);
	else if(strcmp("cos", s)==0)	*res = cos(arg);
	else if(strcmp("tan", s)==0)	*res = tan(arg);
	else if(strcmp("exp", s)==0)	*res = exp(arg);
	else if(strcmp("log", s)==0){
		if(arg<=0){ printf("Error: value out of function %s(x) domain\n", s); return -1;}
		*res = log(arg);
	}
	else if(strcmp("asin", s)==0){
		if(arg<-1 || arg>1){ printf("Error: value out of function %s(x) domain\n", s); return -1;}
		*res = asin(arg);
	}
	else if(strcmp("acos", s)==0){
		if(arg<-1 || arg>1){ printf("Error: value out of function %s(x) domain\n", s); return -1;}
		*res = acos(arg);
	}
	else if(strcmp("atan", s)==0)	*res = atan(arg);
	else if(strcmp("sec", s)==0)	*res = 1/sin(arg);
	else if(strcmp("cosec", s)==0)	*res = 1/cos(arg);
	else if(strcmp("cotan", s)==0)	*res = 1/tan(arg);
	else if(strcmp("sqrt", s)==0){
		if(arg<0){ printf("Error: value out of function %s(x) domain\n", s); return -1;}
		*res = pow(arg, 0.5);
	}
	else if(strcmp("fact", s)==0){
		if(arg<0){ printf("Error: value out of function %s(x) domain\n", s); return -1;}
		*res=1;
		for(int i=2; i<=arg; i++){
			*res = *res*i;
		}
	}
	else return -1;
	return 0;
}

