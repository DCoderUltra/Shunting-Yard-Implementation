// Stack Headers
void init(ST** PES);
int empty(ST * PES);
void add(ST **PES, TOKEN t_in);
void pop(ST** PES);
void list(ST *PES);
TOKEN top(ST* PES);

// Queue Headers
void init_q(QE ** queue);
int empty_q(QE * queue);
void enqueue(QE ** queue, TOKEN tok);
void dequeue(QE ** queue);
void dequeue_all(QE **queue);
void count_q(QE * queue, int *c);
void list_q(QE * queue);
TOKEN first(QE * queue);

