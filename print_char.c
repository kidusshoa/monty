#include "monty.h"

/**
 * f_pchar - print the char at the top of stack
 * @head: stack head
 * @counter: line counter
 *
 * Return: none
 */

void f_pchar(stack_t **head, unsigned int counter)
{
    stack_t *h = *head;

    if (h == NULL) {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (h->n <= 0 || h->n > 127) {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    putchar(h->n);
    putchar('\n');
}
