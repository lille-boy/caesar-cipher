/**************************************************************************************************
 *
 * Main Program.
 *
 *************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "caesar.h"


/******************************************************************************
 * Main
 *****************************************************************************/
int main(int argc, char *argv[])
{
    struct user_input input;

    if (argc > 1) {
        input.option = argv[1];

        if (DEBUG) {
            printf("option: %c\n", *input.option);
        }

        if (argc > 2) {
            char *c;
            input.key = strtol(argv[2], &c, 10);

            if (DEBUG) {
                printf("key: %d\n", input.key);
            }

            if(argc > 3) {
                char *in_file_path = argv[3];
                input.in_message = fopen(in_file_path, "r");

                if (input.in_message != NULL) {
                    if (argc > 4) {
                        char *out_file_path = argv[4];
                        input.out_message = fopen(out_file_path, "w");
                    }
                    else {
                        printf("No output file specified. Stored in output.txt\n");
                        input.out_message = fopen("ouput.txt", "w");
                    }

                    if (input.out_message != NULL) {
                        caesar_substitution(&input);
                    }
                    fclose(input.out_message);
                }
                fclose(input.in_message);
            }
            else {
                printf("Error, missing arguments\n");
            }
        }
        else {
            printf("Error, missing arguments\n");
        }
    }
    else {
        printf("Error, missing arguments\n");
    }

    return 0;
}
