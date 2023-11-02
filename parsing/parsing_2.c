/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:58:52 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 13:58:18 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_duble_quotes(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	*i += 1;
	while (s[(*i)])
	{
		if (s[(*i)] == '\"')
		{
			*i += 1;
			return ;
		}
		*i += 1;
	}
	globle_error(flag);
}

void	ft_singel_quotes(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	*i += 1;
	while (s[(*i)])
	{
		if (s[(*i)] == '\'')
		{
			*i += 1;
			return ;
		}
		*i += 1;
	}
	globle_error(flag);
}

int	ft_2doller(char *s, int *flag, int *i)
{
	if (s[*i] == '$' && s[*i + 1] == '\0')
	{
		*i += 1;
		return (1);
	}
	if (s[*i] == '$' && ft_strchr("$#*@0123456789?!-_", s[*i + 1])
		&& (ft_strchr("\'\" \t\v\r\f|", s[*i + 2]) || s[*i + 2] == '\0'))
	{
		*i += 2;
		return (1);
	}
	if (!ft_isalnum(s[*i]) && !ft_strchr("_ \t\v\r\f\'\"$", s[*i]) && s[*i] != '\0')
	{
		globle_error(flag);
		return (1);
	}
	return (0);
}

void	ft_doller_varble(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	if (ft_2doller(s, flag, i))
		return ;
	*i += 1;
	while (s[*i] && !ft_strchr("<>\'\"| \t\v\r\f", s[*i]))
	{
		if (!ft__doller(s[*i]) && s[*i] != '_')
		{
			globle_error(flag);
			return ;
		}
		*i += 1;
	}
}

void	fun2sky(char *s, int *i, int c)
{
	if (!s || !i)
		return ;
	*i += 1;
	while (s[*i])
	{
		if (s[*i] == c)
			break ;
		*i += 1;
	}
}
