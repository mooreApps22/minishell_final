/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_tok_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:35:14 by smoore            #+#    #+#             */
/*   Updated: 2025/02/07 13:35:17 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"

void	assign_tok_types(t_token *head);

static void	assign_symbols(t_token *head)
{
	t_token	*cur;	
	
	cur = head;
	while (cur)
	{
		if (word_match(cur->str, "|"))
			cur->type = PIPE;
		else if (word_match(cur->str, "<"))
			cur->type = RE_READ;
		else if (word_match(cur->str, "<<"))
			cur->type = RE_HEREDOC;
		else if (word_match(cur->str, ">"))
			cur->type = RE_TRUNC;
		else if (word_match(cur->str, ">>"))
			cur->type = RE_APPEND;
		cur = cur->next;
	}
}

static void	assign_files(t_token *head)
{
	t_token	*cur;	
	
	cur = head;
	while (cur)
	{
		if (cur->prev && cur->type == ARG && cur->prev->type == RE_READ)
			cur->type = FN_READ;
		else if (cur->prev && cur->type == ARG && cur->prev->type == RE_HEREDOC)
			cur->type = DELIM;
		else if (cur->prev && cur->type == ARG && cur->prev->type == RE_TRUNC)
			cur->type = FN_TRUNC;
		else if (cur->prev && cur->type == ARG && cur->prev->type == RE_APPEND)
			cur->type = FN_APPEND;
//		else if (word_match(cur->str, "$?"))
//			cur->type = EXIT_STAT;
		cur = cur->next;
	}
}

static void	assign_cmds(t_token *head)
{
	t_token	*cur;	
	bool	first;
	
	cur = head;
	first = true;
	while (cur)
	{
		if (first && cur->type == ARG)
		{
			cur->type = CMD;
			first = false;
		}
		else if (!first && cur->type == PIPE)
			first = true;
		cur = cur->next;
	}
}

void	assign_tok_types(t_token *head)
{
	assign_symbols(head);
	assign_files(head);
	assign_cmds(head);
}
