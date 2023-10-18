#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        more_err(8, line_number, "mul");
    }

    stack_t *first = *stack;
    stack_t *second = (*stack)->next;

    int product = first->n * second->n;
    second->n = product;

    *stack = second;
    (*stack)->prev = NULL;

    free(first);
}

/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL) {
        more_err(8, line_number, "mod");
    }

    stack_t *first = *stack;
    stack_t *second = (*stack)->next;

    if (first->n == 0) {
        more_err(9, line_number);
    }

    int remainder = second->n % first->n;
    second->n = remainder;

    *stack = second;
    (*stack)->prev = NULL;

    free(first);
}
