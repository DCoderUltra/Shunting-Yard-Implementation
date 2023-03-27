// Token definition
typedef struct{
	char string[256];
	int assoc;
	int prec;
}TOKEN;

// Stack Node Definition
typedef struct stackElem
{
	TOKEN t;
	struct stackElem *next;
} ST;

typedef struct queueElem
{
	TOKEN t;
	struct queueElem * ahead;
	struct queueElem * behind;
}QE;

