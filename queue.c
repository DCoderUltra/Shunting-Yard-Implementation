#include<stdio.h>
#include<stdlib.h>

#include "global.c"

void init_q(QE ** queue){
	*queue=NULL;
}

int empty_q(QE * queue){
	return (queue==NULL);
}


void enqueue(QE ** queue, TOKEN tok){
	QE *tmp = malloc(sizeof(QE)*2);
	if(tmp==NULL) return;

	if( (*queue) == NULL){
		tmp -> t = tok;
		tmp -> ahead = *queue;
		tmp -> behind = NULL;
		*queue = tmp;
	}
	else if((*queue)->ahead != NULL)
	{
		tmp -> t = tok;
		tmp -> ahead = *queue;
		tmp -> behind = NULL;
		(*queue) -> behind = tmp;
	}
	else
		enqueue(&((*queue)->behind),tok);
}

void dequeue(QE ** queue){

	QE *tmp = malloc(sizeof(QE)*2);
	if(tmp==NULL) return;

	tmp = (*queue);
	//if((*queue)->behind!=NULL)
	*queue = (*queue)->behind;
	//else *queue=NULL;
	free(tmp);
}

void dequeue_all(QE **queue){
	QE *tmp = malloc(sizeof(QE)*2);
	while(!empty_q(*queue)){
		tmp = (*queue);
		*queue = (*queue)->behind;
		free(tmp);
	}
}

void list_q(QE * queue){
	if (empty_q(queue)) return;
	printf("%s ", (queue->t).string);
	list_q(queue->behind);
}

void count_q(QE * queue, int *c){
	if (empty_q(queue)) return;
	*c=*c+1;
	count_q(queue->behind, c);
}

TOKEN first(QE * queue){
	return queue->t;
}

