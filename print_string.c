#include "monty.h"

/**
 * f_pstr - print string at the top of stack
 * @head: first node of linked list
 * @counter: line counter
 *
 * Return: none
 */

void f_pstr(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;
    (void)counter;

    while (current != NULL && current->n > 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }

    printf("\n");
}
