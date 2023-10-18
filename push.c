#include "monty.h"

/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @counter: line count
 *
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int counter)
{
    int i, m = 0, flag = 0;

    if (bus.arg == NULL) {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (bus.arg[0] == '-') {
        m++;
    }

    for (; bus.arg[m] != '\0'; m++) {
        if (bus.arg[m] > '9' || bus.arg[m] < '0') {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    i = atoi(bus.arg);
    if (bus.lifi == 0) {
        addnode(head, i);
    } else {
        addqueue(head, i);
    }
}
