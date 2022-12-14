#include"monty.h"
/**
 *get_op_code - select the operation
 *@s: string with the symbol
 *@l_n: line number
 *@token: token
 *Return: pointer to a function selected
 */
void (*get_op_code(char *s, int l_n, char *token))(stack_t **, unsigned int)
{
	int i = 0, j = 0;
	char *err = "unknown instruction";
	instruction_t opcodes[] = {
		{"push", op_push},
		{"qush", op_qush},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"rotl", op_rotl},
		{"pstr", op_pstr},
		{"rotr", op_rotr},
		{NULL, NULL}
	};
	while (opcodes[i].opcode && s)
	{
		j = 0;
		while (opcodes[i].opcode[j] == s[j] && s[j])
			j++;
		if (!opcodes[i].opcode[j] && !s[j])
		{
			return (opcodes[i].f);
		}
		i++;
	}
	if (opcodes[i].f == NULL)
	{
		fprintf(stderr, "L%d: %s %s\n", l_n, err, token);
		exit(EXIT_FAILURE); }
	return (NULL);
}
