#include "monty.h"
/**
 *op_rotr - reverse the list
 *@stack: stack
 *@line_number: line number
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1;

	line_number++;
	if (!stack || !*stack || !(*stack)->next)
	{
		;
	}
	else
	{
		aux1 = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->next = aux1;
		(*stack)->prev = NULL;
		aux1->prev = *stack;
	}
}

