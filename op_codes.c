#include"monty.h"
/**
 *op_push - add anode
 *@stack: head node
 *@line_number: number of line in file
 *Return: new node
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		freel(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 *op_pall - print all
 *@stack: head node
 *@line_number: number of line in file
 *Return: new node
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *aux;
	(void) line_number;
	if (!stack || !*stack)
		;
	else
	{
		aux = *stack;
		while (aux->next)
		{
			i++;
			printf("%d\n", aux->n);
			aux = aux->next;
		}
		printf("%d\n", aux->n);
	}
}
/**
 *op_pint - prints the value at the top of the stack
 *@stack: head node
 *@line_number: number of line in file
 *Return: new node
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 *op_pop - removes the top element of the stack
 *@stack: head node
 *@line_number: number of line in file
 *Return: new node
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	if (aux->next)
		aux->next->prev = NULL;
	*stack = aux->next;
	free(aux);
}
/**
 *op_swap - swaps the top two elements of the stack
 *@stack: head node
 *@l_number: number of line in file
 *Return: new node
 */
void op_swap(stack_t **stack, unsigned int l_number)
{
	stack_t *aux;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_number);
		exit(EXIT_FAILURE);

	}
	aux = *stack;
	*stack = aux->next;
	(*stack)->prev = NULL;
	aux->next = (*stack)->next;
	aux->prev = *stack;
	if (aux->next)
		(aux->next)->prev = aux;
	(*stack)->next = aux;
}
