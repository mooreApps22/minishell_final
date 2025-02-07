#include "../inc/data.h"

bool	word_match(char *word, char *check);
bool	is_blank(char c);
bool	is_symbol(char c);
bool	is_quote(char c);
int		quoted_strlen(char *str);

bool	word_match(char *word, char *check)
{
	if (ft_strncmp(word, check, ft_strlen(word)) == 0)
		return (true);
	return (false);
}

bool	is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

bool	is_symbol(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

bool	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	quoted_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_blank(str[i]) && !is_symbol(str[i]))
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\'')
				i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (str[i] == '\"')
				i++;
		}
		else
		{
			while (str[i] && !is_blank(str[i])
				&& !is_quote(str[i]) && !is_symbol(str[i]))
				i++;
		}
	}
	return (i);
}
