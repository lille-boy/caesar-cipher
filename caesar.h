
#define DEBUG   1

struct user_input {
    char *option;
    unsigned int key;
    FILE *in_message;
    FILE *out_message;
};

/******************************************************************************
 * Input:
 * Output:
 *****************************************************************************/
void caesar_substitution(struct user_input *user);
