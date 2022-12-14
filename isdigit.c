#include "monty.h"
/**
 *_isdigit - select the operation
 *@s: string to compare
 *Return: y/n
 */
char _isdigit(char *s)
{
	int i = 0, f1 = 0;

	if (s[0] == '-')
		i++;
	while (s[i] && f1 == 0)
	{
		if (s[i] > 47 && s[i] < 58)
			i++;
		else
			f1 = 1;
	}
	if (f1 == 0)
	{
		n = atoi(s);
		return ('y');
	}
	else
		return ('n');
}
