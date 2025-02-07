#include "../inc/data.h"

bool	has_quotes(char *str);
static bool	calculate_if_finished(int single_quotes, int double_quotes);
bool	has_finished_quotes(char *str);
static char	get_last_quote(char *input);
char	*finish_quotes(char *input);

bool	has_quotes(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			return (true);
		i++;	
	}
	return (false);
}

static bool	calculate_if_finished(int single_quotes, int double_quotes)
{
	bool	finished;

	finished = false;
	if ((single_quotes % 2 == 0) && (double_quotes % 2 == 0))
		finished = true; 
	else
		finished = false; 
	return (finished);
}

bool	has_finished_quotes(char *str)
{
	int		i;
	int 	single_quotes;
	int 	double_quotes;
	bool	finished;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	finished = false;
	while (str[i])
	{
		if (str[i] == '\'')
			single_quotes++;
		if (str[i] == '\"')
			double_quotes++;
		i++;	
	}
	finished = calculate_if_finished(single_quotes, double_quotes);
	return (finished);
}

static char	get_last_quote(char *input)
{
	int		len;
	int		i;

	len = ft_strlen(input) - 1;
	i = 0;
	while (i < len)
	{
		if (is_quote(input[len]))
			return (input[len]);
		len--;
	}
	return ('x');
}

char	*finish_quotes(char *input)
{
	char	quote;
	char	*buf;
	char	*str1;
	char	*join;
	bool	found;

	found = false;
	quote = get_last_quote(input);
	join = ft_strjoin(input, "\n");
	if (quote == 'x')
	{
		free(join);
		return (NULL);
	}
	while (!found)
	{
		str1 = ft_strdup(join);
		free(join);
		ft_putstr_fd("> ", STDOUT_FILENO);
		buf = get_next_line(STDIN_FILENO);
        join = ft_strjoin(str1, buf);
        free(str1);
		if (ft_strchr(buf, quote))
			found = true;
		free(buf);
	}
	return (join);
}
