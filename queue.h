// Queue Header File
void init_q(QE ** queue);
int empty_q(QE * queue);
void enqueue(QE ** queue, TOKEN tok);
void dequeue(QE ** queue);
void list_q(QE * queue);
TOKEN first(QE * queue);

