#ifndef CAESAR_H
#define CAESAR_H

#define DEBUG   0

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

#endif /* CAESAR_H */
