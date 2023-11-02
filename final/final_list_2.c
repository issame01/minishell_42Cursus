/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:45 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 03:58:36 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

char	*ft_strjoin_herd(char *s1, char *s2)
{
	char	*str;
	int		j;
	int		o;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		malloc_exit();
	j = 0;
	o = 0;
	while (s1[j] != '\0')
		str[o++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[o++] = s2[j++];
	str[o] = '\0';
	free(s2);
	return (str);
}

void	herd_not_expand(char *input)
{
	char	*s1;

	if (!input)
		return ;
	s1 = ft_charjoin(input, '\n');
	g_var.buffer = ft_strjoin(g_var.buffer, s1);
}

void	herd1(char *input, t_env **env)
{
	if (!input)
		return ;
	if (g_var.herd_expand == 0)
		herd_expand(input, env);
	else
		herd_not_expand(input);
}

static void	ft_link_fun(t_tmp *tmp)
{
	tmp->input = file_herd();
	write(tmp->input, g_var.buffer, ft_strlen(g_var.buffer));
	free(g_var.buffer);
	close(tmp->input);
	tmp->input = open(g_var.file, O_RDONLY, 0777);
	tofree();
}

void	herd(t_tmp *tmp, char *delimiter, t_env **env)
{
	char	*input;

	if (!delimiter)
		return ;
	g_var.buffer = ft_strdup("");
	g_var.flag_herd = 1;
	while (1)
	{
		input = readline("> ");
		signal(SIGINT, handler);
		if (!isatty(STDIN_FILENO))
			dup2(STDIN_FILENO, open(ttyname(1), O_RDONLY, 0644));
		if (!input || ft_cmp_to_str(input, delimiter))
		{
			ft_link_fun(tmp);
			break ;
		}
		herd1(input, env);
	}
	g_var.flag_herd = 0;
	free(input);
}
