#include "../inc/data.h"

void	cleanup_child(t_data *data, int exit_status);

void	cleanup_child(t_data *data, int exit_status)
{
	if (data)
	{
		free_minishell(data);
		ft_str_arr_free(&data->env);
		free(data);
	}
	exit(exit_status);
}
