#include"monty.h"
/**
 *freel - free lsit
 *@stack: head
 *Return: void
 */
void freel(stack_t *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			free(stack->prev);
		}
		free(stack);
	}
}
