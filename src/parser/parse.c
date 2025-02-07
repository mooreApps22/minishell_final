#include "../inc/data.h"

void	parse(t_data *data);

void	parse(t_data *data)
{
	t_token	*cur;
	t_cmd	*new;

	cur = data->toks;
	while (cur)
	{
		new = cmd_lstnew(&cur, data);
		cmd_lstadd_back(&data->cmds, new);
		data->cmd_ct++;
	}
	data->pipe_ct = data->cmd_ct - 1;
	get_expansions(&data->cmds, data);
	get_heredocs(&data->cmds, data);
}
