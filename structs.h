// Stack Headers
void init(ST** PES);
int empty(ST * PES);
void add(ST **PES, TOKEN t_in);
void pop(ST** PES);
void list(ST *PES);
TOKEN top(ST* PES);
// Queue Headers
void init_queue(QE ** queue);
int empty_queue(QE * queue);
void enqueue(QE ** lead, QE **tail, TOKEN tok);
void dequeue(QE ** tail);
void count_q(QE * queue, int *c);
void list_q(QE * queue);
TOKEN first(QE * lead);

