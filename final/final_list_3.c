/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:56:36 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 03:58:54 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		free(s[i++]);
	free(s);
	s = NULL;
}

void	tofree(void)
{
	unlink(g_var.file);
	free(g_var.file);
}

long	file_herd(void)
{
	static long	i;
	int			fd;

	g_var.file = ft_strjoin_herd("/tmp/.file", ft_itoa(++i));
	fd = open(g_var.file, O_CREAT | O_TRUNC | O_RDWR, 0777);
	return (fd);
}

void	ft_cmd_final(t_cmd **_cmd, t_tmp *tmp)
{
	t_cmd	*cmd;
	t_cmd	*path;

	if (!tmp)
		return ;
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		malloc_exit();
	if (g_var.str && g_var.str[0] != NULL)
		cmd->cmd = ft_str_two_ptr(g_var.str);
	else
		cmd->cmd = NULL;
	ft_free(g_var.str);
	cmd->file_input = tmp->input;
	cmd->file_output = tmp->output;
	cmd->next = NULL;
	if (*_cmd == NULL)
	{
		*_cmd = cmd;
		return ;
	}
	path = *_cmd;
	while (path->next != NULL)
		path = path->next;
	path->next = cmd;
}

void	ft_void(char **s, int i)
{
	int	j;

	j = 0;
	while (j < i)
		s[j++] = NULL;
}
