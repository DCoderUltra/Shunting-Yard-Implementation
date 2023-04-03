// Stack implementation for tokens
#include<stdio.h>
#include<stdlib.h>

#include "global.c"

void init(ST** PES)
{
	*PES=NULL;
}

int empty(ST * PES)
{
	return (PES==NULL);
}

void add(ST **PES, TOKEN t_in)
{
	ST *tmp;
	tmp = malloc(sizeof(ST)*2);
	if(tmp==NULL) return;
	tmp->t = t_in;
	tmp->next = *PES;
	*PES = tmp;
}

void pop(ST** PES)
{
	if(!empty(*PES)){
		ST *tmp = *PES;
		*PES = (*PES)->next;
		//free(tmp);
	}
}

TOKEN top(ST* PES)
{
	if(!empty(PES))
		return PES->t;
}

void list(ST *PES)
{
	if (empty(PES))
		return;
	printf("%s\n", (PES->t).string);
	list(PES->next);
}

/* To do on the main.c file.
int main()
{
	ST *PES;
	init(&PES);
} */

