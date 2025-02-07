#include "../inc/data.h"

void	print_execute(t_data *data);

void	print_execute(t_data *data)
{
	t_cmd	*job;
	t_ins	*in;
	t_outs	*out;
	int		i;
	int		j;

	job = data->cmds;

	printf("Begin job:\n");
	i = 0;
	j = 0;
	in = NULL;
	out = NULL;
	printf("\theredoc_ct: %d\n", data->heredoc_ct);
	while (job)
	{
		j = 0;
		printf("Cmd# %d\n", i);
		while (job->cmdv[j])
		{
			printf("\tcmdv: %s\n", job->cmdv[j++]);
		}
		if (job->ins)
			in = job->ins;
		while (in)
		{
			printf("\tread_fn: %s\n", in->read_fn);
			if (in->eof)
				printf("\teof: %s\n", in->eof);
			printf("\teof_len: %d\n", in->eof_len);
			printf("\tfd: %d\n", in->fd);
			in = in->next;
		}
		if (job->outs)
			out = job->outs;
		while (out)
		{
			if (out->trunc_fn)
				printf("\ttrunc_fn: %s\n", out->trunc_fn);
			if (out->append_fn)
				printf("\tappend_fn: %s\n", out->append_fn);

			out = out->next;
		}
		job = job->next;
		i++;
	}
}
