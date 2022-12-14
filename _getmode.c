#include "monty.h"
/**
 *_getmode - stack or queue
 *@s: token
 *@fm: flag mode
 *Return: flag
 */
int _getmode(char *s, int *fm)
{
	int i = 0, j = 0;
	modes_t modes[] = {
		{"stack", 1},
		{"queue", 2},
		{"push", 3},
		{NULL, 0}
	};

	while (modes[i].mode && s)
	{
		j = 0;
		while (modes[i].mode[j] == s[j] && s[j])
			j++;
		if (!modes[i].mode[j] && !s[j])
		{
			if (modes[i].m == 1 || modes[i].m == 2)
				*fm = modes[i].m;
			return (modes[i].m);
		}
		i++;
	}
	return (0);
}
