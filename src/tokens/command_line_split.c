#include "../inc/data.h"

char	**command_line_split(char *line);

char	**command_line_split(char *line)
{
	char	**words;
	int		start;
	int		ct;
	int		i;

	i = 0;
	ct = 0;
	words = allocate_words_memory(line);
	while (line[i])	
	{
		while (is_blank(line[i]))
			i++;
		start = i;
		if (is_symbol(line[i]))
		{
			i++;
			if (line[i] == line[i - 1] && line[i] != '|')
				i++;
		}
		else if (line[i])
			i += quoted_strlen(&line[start]);
		words[ct++] = ft_substr(line, start, i - start);
	}
	return (words);
}
