/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:46:24 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 13:59:08 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	check_pipe(char *s, int *flag)
{
	int	i;
	int	word;
	int	pipe;

	if (!s || !flag)
		return ;
	i = 0;
	word = 0;
	pipe = 0;
	while (s[i] && ft_strchr(" \t\v\r\f", s[i]))
		i++;
	if (s[i] == '|')
	{
		globle_error(flag);
		return ;
	}
	while (s[i])
	{
		check_pipe2(s, &word, &pipe, &i);
	}
	if (pipe + 1 == word)
		return ;
	globle_error(flag);
}

void	check_pipe2(char *s, int *word, int *pipe, int *i)
{
	if (!s || !word || !pipe || !i)
		return ;
	while (s[*i])
	{
		if (s[*i] && !ft_strchr("| \t\v\r\f", s[*i]) && s[*i] != '\0')
		{
			while (s[*i] && !ft_strchr("|", s[*i]) && s[*i] != '\0')
			{
				if (s[*i] == '\'' || s[*i] == '\"')
					fun2sky(s, i, s[*i]);
				*i += 1;
			}
			*word += 1;
		}
		while (s[*i] && ft_strchr(" \t\v\r\f", s[*i]))
			*i += 1;
		if (s[*i] == '|')
		{
			*pipe += 1;
			*i += 1;
		}
	}
}
