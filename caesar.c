/**************************************************************************************************
 *
 * Caesar cipher substitution
 *
 *************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "caesar.h"

#define LINE_LENGTH_MAX 512u
#define ALPHABET_SIZE (26u)

const char lower_case[ALPHABET_SIZE] = \
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const char upper_case[ALPHABET_SIZE] = \
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

/******************************************************************************
 * Shift one character using the key
 * A non-alphabetical characted is not altered
 *****************************************************************************/
static char substitute_one_letter(char letter, unsigned int key)
{
    char shifted = letter;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (letter == lower_case[i]) {
            shifted = lower_case[(i + key) % ALPHABET_SIZE];
            break;
        }
        else if (letter == upper_case[i]) {
            shifted = upper_case[(i + key) % ALPHABET_SIZE];
            break;
        }
    }

    return shifted;
}

/******************************************************************************
 * Encrypt the input sentence
 * Input: pointer to sentence
 * Output: pointer to substitution
 *****************************************************************************/
static void caesar_encrypt(const char *in_line, char *out_line, unsigned int key)
{
    for (int i = 0; i < LINE_LENGTH_MAX; i++) {
        out_line[i] = substitute_one_letter(in_line[i], key);
        if (in_line[i] == '\n') {
			/* exit on end of line */
			break;
		}
    }
}

/******************************************************************************
 * Encrypt the input sentence
 * Input: pointer to sentence
 * Output: pointer to substitution
 *****************************************************************************/
static void caesar_decrypt()
{
}

/******************************************************************************
 * Parses the input file line by line
 *****************************************************************************/
void caesar_substitution(struct user_input *user)
{
    unsigned int line_number = 1;
	char in_line[LINE_LENGTH_MAX];
    char out_line[LINE_LENGTH_MAX];

	while (fgets(in_line, LINE_LENGTH_MAX, user->in_message) != NULL)
	{
        if (DEBUG) {
            printf("line %d: %s\n", line_number, in_line);
        }

        if (*user->option == 'e') {
            caesar_encrypt(in_line, out_line, user->key);
        }
        fputs(out_line, user->out_message);
        fputs("\n", user->out_message);
	}
}
