#include "monty.h"

/**
* f_pall - print everything in stack
* @head: pointer to pointer of first node
* @counter: line counter (not used)
*
* Return: none
*/

void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;
    (void)counter;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
* f_swap - swap first two elements of stack
* @head: first node
* @counter: line counter
*
* Return: none
*/

void f_swap(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int temp;
    
    h = *head;
    if (h == NULL || h->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    temp = h->n;
    h->n = h->next->n;
    h->next->n = temp;
}
