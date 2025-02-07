#include "../inc/data.h"
//if (!is_builtin_cmd(head[0]))// head -> cmdv0

bool	is_builtin_cmd(char *cmdv);

bool	is_builtin_cmd(char *cmdv)
{
	char	*builtins[] = {
		 "cd", "echo", "env", "exit", "export", "pwd", "unset"
	};
	int		i;

	if (!cmdv)
		return (NULL);
	i = 0;
	while (i < 7)
	{
		if (word_match(cmdv, builtins[i]))
			return (true);
		i++;
	}
	return (false);
}
