/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:41:53 by osabir            #+#    #+#             */
/*   Updated: 2023/08/09 14:12:23 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

char	**ft_str_two_ptr(char **s)
{
	char	**s1;
	int		i;
	int		j;

	if (!s || *s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		i++;
	s1 = (char **)malloc((i + 1) * sizeof(char *));
	if (!s1)
		malloc_exit();
	while (s[j] && j < i)
	{
		s1[j] = ft_strdup(s[j]);
		j++;
	}
	s1[j] = NULL;
	return (s1);
}

t_link	*ft_about_type(t_link *link, t_tmp *tmp, t_env **env)
{
	if (link->type == REDI_OUT || link->type == APPEN || link->type == REDI_IN)
	{
		file(tmp, link->cmd, link->next->cmd);
		link = link->next;
	}
	else if (link->type == HERDQ)
	{
		link = link->next;
		herd(tmp, link->cmd, env);
	}
	return (link);
}

void	file(t_tmp *tmp, char *operator, char *file)
{
	if (!operator || !file)
		return ;
	if (ft_cmp_to_str("<", operator))
	{
		if (tmp->input != -2)
			close(tmp->input);
		if (tmp->input != -1 && tmp->output != -1)
			tmp->input = open(file, O_RDONLY);
	}
	else if (ft_cmp_to_str(">>", operator))
	{
		if (tmp->output != -2)
			close(tmp->output);
		if (tmp->output != -1 && tmp->input != -1)
			tmp->output = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	}
	else if (ft_cmp_to_str(">", operator))
	{
		if (tmp->output != -2)
			close(tmp->output);
		if (tmp->output != -1 && tmp->input != -1)
			tmp->output = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	}
}

char	*ft_herd_part(t_env **_env, char *input, int *i)
{
	char	*s1;

	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	while (input[*i])
	{
		if (input[*i] == '$' && input[*i + 1] != '$'
			&& !ft_isdigit(input[*i + 1]))
			s1 = ft_strjoin(s1, ft_expandvar(_env, input, i));
		else
		{
			s1 = ft_charjoin(s1, input[*i]);
			*i += 1;
		}
	}
	free(input);
	return (s1);
}

void	herd_expand(char *input, t_env **env)
{
	char	*s1;
	int		i;

	if (!input)
		return ;
	i = 0;
	s1 = ft_charjoin(ft_herd_part(env, input, &i), '\n');
	g_var.buffer = ft_strjoin(g_var.buffer, s1);
}
