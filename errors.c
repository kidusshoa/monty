#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
 
void err(int error_code, ...)
{
    va_list ag;
    char *error_messages[] = {
        "USAGE: monty file\n",
        "Error: Can't open file %s\n",
        "L%d: unknown instruction %s\n",
        "Error: malloc failed\n",
        "L%d: usage: push integer\n"
    };

    va_start(ag, error_code);

    if (error_code >= 1 && error_code <= 5) {
        int l_num;
        char *op;

        switch (error_code) {
            case 2:
            case 3:
            case 5:
                l_num = va_arg(ag, int);
                op = va_arg(ag, char *);
                fprintf(stderr, error_messages[error_code - 1], l_num, op);
                break;
            case 1:
            case 4:
                fprintf(stderr, error_messages[error_code - 1]);
                break;
        }
    }

    va_end(ag);

    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */

typedef struct {
    int error_code;
    const char *error_message;
    int arg_count;
} ErrorMessage;

void more_err(int error_code, ...)
{
    va_list ag;
    ErrorMessage error_messages[] = {
        {6, "L%d: can't pint, stack empty\n", 1},
        {7, "L%d: can't pop an empty stack\n", 1},
        {8, "L%d: can't %s, stack too short\n", 2},
        {9, "L%d: division by zero\n", 1}
    };

    va_start(ag, error_code);

    for (int i = 0; i < sizeof(error_messages) / sizeof(error_messages[0]); i++) {
        if (error_code == error_messages[i].error_code) {
            int arg_count = error_messages[i].arg_count;
            fprintf(stderr, error_messages[i].error_message, va_arg(ag, int), va_arg(ag, int));
            for (int j = 0; j < arg_count; j++) {
                va_arg(ag, int);
            }
            break;
        }
    }

    va_end(ag);

    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */


typedef struct {
    int error_code;
    const char *error_message;
} ErrorMessage;

void string_err(int error_code, ...)
{
    va_list ag;
    ErrorMessage error_messages[] = {
        {10, "L%d: can't pchar, value out of range\n"},
        {11, "L%d: can't pchar, stack empty\n"}
    };

    va_start(ag, error_code);

    int l_num = va_arg(ag, int);

    for (int i = 0; i < sizeof(error_messages) / sizeof(error_messages[0]); i++) {
        if (error_code == error_messages[i].error_code) {
            fprintf(stderr, error_messages[i].error_message, l_num);
            break;
        }
    }

    va_end(ag);

    free_nodes();
    exit(EXIT_FAILURE);
}
