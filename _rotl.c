#include "monty.h"
/**
 *op_rotl - rot the list
 *@stack: stack
 *@line_number: line number
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1, *aux2;

	line_number++;
	if (!stack || !*stack || !((*stack)->next))
		;
	else
	{
		aux2 = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		aux1 = *stack;
		while (aux1->next)
		{
			aux1 = aux1->next;
		}
		aux1->next = aux2;
		aux2->prev = aux1;
		aux2->next = NULL;
	}
}
