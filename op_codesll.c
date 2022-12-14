#include"monty.h"
/**
 *op_add - adds the top two elements of the stack
 *@stack: head node
 *@l_number: number of line in file
 *Return: new node
 */
void op_add(stack_t **stack, unsigned int l_number)
{
	int sub_n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_number);
		exit(EXIT_FAILURE);
	}
	sub_n = (*stack)->n;
	op_pop(stack, l_number);
	(*stack)->n = (*stack)->n + sub_n;
}
/**
 *op_nop - doesn’t do anything
 *@stack: head node
 *@line_number: number of line in file
 *Return: new node
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	;
}
/**
 *op_sub - subtracts the top element of the
 *stack from the second top element of the stack.
 *@stack: pointer  to head node
 *@l_number: number of line in file
 *Return: no return
 */
void op_sub(stack_t **stack, unsigned int l_number)
{
	int sub_n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_number);
		exit(EXIT_FAILURE);
	}
	sub_n = (*stack)->n;
	op_pop(stack, l_number);
	(*stack)->n = (*stack)->n - sub_n;
}
/**
 *op_div - subtracts the top element of the
 *stack from the second top element of the stack.
 *@stack: pointer  to head node
 *@l_number: number of line in file
 *Return: new node
 */
void op_div(stack_t **stack, unsigned int l_number)
{
	int sub_n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_number);
		exit(EXIT_FAILURE);
	}
	sub_n = (*stack)->n;
	op_pop(stack, l_number);
	(*stack)->n = (*stack)->n / sub_n;
}
/**
 *op_mul - multiplies the second top
 *element of the stack with the top element of the stack.
 *stack from the second top element of the stack.
 *@stack: pointer  to head node
 *@l_number: number of line in file
 *Return: new node
 */
void op_mul(stack_t **stack, unsigned int l_number)
{
	int sub_n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_number);
		exit(EXIT_FAILURE);
	}
	sub_n = (*stack)->n;
	op_pop(stack, l_number);
	(*stack)->n = (*stack)->n * sub_n;
}
