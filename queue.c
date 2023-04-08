#include<stdio.h>
#include<stdlib.h>

#include "global.c"

void init_queue(QE ** node){
	*node=NULL;
}

int empty_queue(QE * node){
	return (node==NULL);
}


void enqueue(QE ** lead, QE ** tail, TOKEN tok){
	QE * new_node = (QE *) malloc(sizeof(QE));
	if(new_node==NULL) return;
	new_node -> t = tok;

	if(empty_queue(*lead)){
		new_node->ahead = NULL;
		new_node->behind = NULL;
		*lead = new_node;
		*tail = new_node;
	}
	else{
		new_node->ahead = *tail;
		new_node->behind = NULL;
		(*tail)->behind = new_node;
		*tail = new_node;
	}

}

void dequeue(QE ** tail){
	if(empty_queue(*tail)) return;
	QE * tmp = *tail;
	*tail = (*tail)->behind;
	free(tmp);
}

void list_q(QE * queue){
	if (empty_queue(queue)) return;
	printf("%s ", (queue->t).string);
	list_q(queue->behind);
}

void count_q(QE * queue, int *c){
	if (empty_queue(queue)) return;
	*c=*c+1;
	count_q(queue->behind, c);
}

TOKEN first(QE * queue){
	return queue->t;
}

