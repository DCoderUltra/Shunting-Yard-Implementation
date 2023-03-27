#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256

char * replace(char *s, float x)
{
	char *new_s = (char *) malloc(sizeof(s));
	char *iter = s;
	char *digits = malloc(sizeof(x)+1);
	sprintf(digits, "%f", x);
	int n_digits = strlen(digits);

	while(*iter!='\0'){
		if(*iter=='x'){
			*iter='\0';
			strcat(new_s, s);
			strcat(new_s, digits);
			strcat(new_s, iter+1);
			s=new_s;
		}
		iter++;
	}

	return new_s;
}

