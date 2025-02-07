#include "../inc/data.h"

void	builtin_exit(t_data *data);

void	builtin_exit(t_data *data)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	ft_str_arr_free(&data->env);
	free_minishell(data);
	free(data);
	exit(EXIT_SUCCESS);
}
