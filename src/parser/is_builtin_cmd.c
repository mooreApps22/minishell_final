/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:37:40 by smoore            #+#    #+#             */
/*   Updated: 2025/02/07 13:37:41 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"

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
