/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:35:31 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 23:04:27 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	final_list(t_cmd **_cmd, t_link **_link, t_env **env)
{
	t_link	*link;
	t_tmp	tmp;
	int		j;

	if (!_link)
		return ;
	link = *_link;
	while (link && g_var.stop == 0)
	{
		j = ft_tmp(link, &tmp);
		link = final_list2(link, &tmp, j, env);
		ft_cmd_final(_cmd, &tmp);
		if (link->type == PIPE)
			link = link->next;
		else
			return ;
	}
}

char	*ft_strdup_final_fun(const char *s1)
{
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		malloc_exit();
	return (ft_memcpy(str, (char *)s1, ft_strlen(s1) + 1));
}

t_link	*final_list2(t_link *link, t_tmp *tmp, int j, t_env **env)
{
	int	i;

	i = 0;
	while (link && link->type != PIPE && g_var.stop == 0)
	{
		if (link->type == REDI_OUT || link->type == APPEN
			|| link->type == REDI_IN || link->type == HERDQ)
			link = ft_about_type(link, tmp, env);
		else
		{
			if (i < j)
			{
				if (link && link->cmd)
					g_var.str[i++] = ft_strdup_final_fun(link->cmd);
				else
					g_var.str[i] = NULL;
			}
		}
		if (!link || !link->next)
			break ;
		link = link->next;
	}
	return (link);
}

int	ft_tmp(t_link *link, t_tmp *tmp)
{
	int	j;

	if (!link || !tmp)
		return (0);
	j = ft_size(link);
	g_var.str = (char **)malloc(sizeof(char *) * (j + 1));
	if (!g_var.str)
		return (0);
	ft_void(g_var.str, j + 1);
	tmp->input = -2;
	tmp->output = -2;
	return (j);
}

int	ft_size(t_link *link)
{
	int	i;
	int	j;

	if (!link)
		return (0);
	i = 0;
	j = 0;
	while (link && link->type != PIPE)
	{
		i++;
		if (link->type == APPEN || link->type == HERDQ
			|| link->type == REDI_OUT || link->type == REDI_IN)
			j += 2;
		link = link->next;
	}
	return (i - j);
}
