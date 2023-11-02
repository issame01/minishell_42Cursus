/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linked.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:44:25 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 01:30:30 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env *_free)
{
	t_env	*curr;
	t_env	*aux;

	if (!_free)
		return ;
	curr = _free;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux->key);
		free(aux->value);
		free(aux);
	}
	_free = NULL;
}

void	free_cmd(t_cmd **_free)
{
	t_cmd		*curr;
	t_cmd		*aux;

	if (!_free || *_free == NULL)
		return ;
	curr = *_free;
	while (curr != NULL)
	{
		aux = curr;
		if (curr->file_input != -2)
			close(curr->file_input);
		if (curr->file_output != -2)
			close(curr->file_output);
		curr = curr->next;
		ft_free(aux->cmd);
		free(aux);
	}
	*_free = NULL;
}

void	free_link(t_link **_free)
{
	t_link		*curr;
	t_link		*aux;

	curr = *_free;
	if (!_free || *_free == NULL)
		return ;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		if (aux->cmd)
		{
			free(aux->cmd);
			aux->cmd = 0;
		}
		free(aux);
	}
	*_free = NULL;
}

void	ign(int ac, char **av)
{
	(void)ac;
	(void)av;
	g_var.ignore = 0;
	rl_catch_signals = 0;
	g_var.buffer = 0;
}
