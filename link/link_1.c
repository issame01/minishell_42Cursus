/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:36:14 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 23:43:45 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	give_info(t_link **_cmd, char *s, t_info type)
{
	t_link	*cmd1;

	if (!_cmd || !s || !type)
		return ;
	cmd1 = *_cmd;
	if (type == ENV_VAR && s[0] == 0)
		cmd1->cmd = NULL;
	else
		cmd1->cmd = ft_strdup(s);
	if (g_var.fre == 0)
		free(s);
	g_var.fre = 0;
	cmd1->type = type;
	cmd1->next = NULL;
}

void	ft_tokenizer_cmd(t_link **cmd, char *s, t_info type)
{
	t_link	*cmd_next;
	t_link	*path;

	if (!s || !type)
		return ;
	cmd_next = malloc(sizeof(t_link));
	if (!cmd_next)
		malloc_exit();
	give_info(&cmd_next, s, type);
	if (*cmd == NULL)
	{
		*cmd = cmd_next;
		return ;
	}
	path = *cmd;
	while (path->next != NULL)
		path = path->next;
	path->next = cmd_next;
}

void	ft_token_append(t_link **cmd, int *i)
{
	if (!i)
		return ;
	*i += 1;
	ft_tokenizer_cmd(cmd, ft_strdup(">>"), APPEN);
}
