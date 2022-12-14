#include "monty.h"
/**
 *op_pstr - prints the string starting at the top of the stack
 *@stack: pointer to head node
 *@line_number: line number
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	line_number++;
	if (!stack || !*stack)
		putchar('\n');
	else if ((*stack)->next == NULL)
	{
		if ((*stack)->n >= 0 && (*stack)->n < 128)
			putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		while (tmp && tmp->n != 0)
		{
			if (tmp->n >= 0 && tmp->n < 128)
				putchar(tmp->n);
			else
				break;
			tmp = tmp->next;
		}
		putchar('\n');
	}
}
