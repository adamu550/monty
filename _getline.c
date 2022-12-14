#include"monty.h"
/**
 *_getline - select the operation
 *@file: file to open
 *Return: pointer to a function selected
 */
void _getline(FILE *file)
{
	unsigned int l_n = 1;
	char *buffer = NULL, *token, del[] = " \t\n";
	char *s, a, *e2 = "usage: push integer";
	size_t s_buffer = 1;
	stack_t *stack;
	void (*f)(stack_t **stack, unsigned int line_number);
	int m = 0, fm = 0;

	stack = NULL;
	while (getline(&buffer, &s_buffer, file) != -1)
	{	token = strtok(buffer, del);
		if (!token || token[0] == '#')
		{	l_n++;
			continue; }
		m = _getmode(token, &fm);
		if (m == 1 || m == 2)
		{	l_n++;
			continue; }
		if (fm == 2 && m != 0)
			token[0] = 'q';
		f = get_op_code(token, l_n, token);
		if (_ifpush(token) == 1)
		{
			s = strtok(NULL, del);
			if (s)
				a = _isdigit(s);
			else
				a = 'n';
			if (a == 'n')
			{
				fprintf(stderr, "L%d: %s\n", l_n, e2);
				exit(EXIT_FAILURE);
			}}
		f(&stack, l_n);
		l_n++; }
	fclose(file);
	freel(stack);
	free(buffer);
}
