// Header file for Tokens


// Association definition
enum Association {A_NONE=0, A_RIGHT=1, A_LEFT=2};

// Function to count the number of tokens
int tok_count(char *s);

// Function to separate tokens
TOKEN * creation(TOKEN *list, char *s, int n_tok);

char * regular(char *s);

