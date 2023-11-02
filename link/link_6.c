/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:27:03 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 22:58:36 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	special_char1(char **s1, char *s, int *i)
{
	if (!s1 || !s || !i)
		return ;
	if (s[*i] == '$' && s[*i + 1] == '?'
		&& (s[*i + 2] == '\0' || ft_strchr("<|>\'\" \t\v\r\f", s[*i + 2])))
	{
		*s1 = ft_strjoin(*s1, ft_exit_status(s, i));
		return ;
	}
	*s1 = ft_charjoin(*s1, '$');
	*i += 1;
	*s1 = ft_charjoin(*s1, s[*i]);
	*i += 1;
}

void	special_char2(t_env **_env, char **s1, char *s, int *i)
{
	if (!_env || !s1 || !s || !i)
		return ;
	*i += 2;
	while (s[*i] && !ft_strchr(" \t\v\r\f", s[*i]) && s[*i] != '\0')
	{
		if (s[*i] == '\"')
			*i += 1;
		else if (s[*i] == '\'')
			*s1 = ft_strjoin(*s1, ft_sing(s, i));
		else if (s[*i] == '$' && (s[*i + 1] == '$' || s[*i + 1] == '\0'))
		{
			*s1 = ft_charjoin(*s1, s[*i]);
			*i += 1;
		}
		else if (s[*i] == '$')
			*s1 = ft_strjoin(*s1, ft_expandvar(_env, s, i));
		else
		{
			*s1 = ft_charjoin(*s1, s[*i]);
			*i += 1;
		}
	}
}

void	special_char3(t_env **_env, char **s1, char *s, int *i)
{
	if (!_env || !s1 || !s || !i)
		return ;
	while (s[*i] && !ft_strchr(" \t\v\r\ft", s[*i] != '\0'))
	{
		if (s[*i] == '\"')
			*i += 1;
		else if (s[*i] == '\'')
			*s1 = ft_strjoin(*s1, ft_sing(s, i));
		else if (s[*i] == '$' && (s[*i + 1] == '$' || s[*i + 1] == '\0'))
		{
			*s1 = ft_charjoin(*s1, s[*i]);
			*i += 1;
		}
		else if (s[*i] == '$')
			*s1 = ft_strjoin(*s1, ft_expandvar(_env, s, i));
		else
		{
			*s1 = ft_charjoin(*s1, s[*i]);
			*i += 1;
		}
	}
}

char	*special_char(t_env **_env, char *s, int *i)
{
	char	*s1;

	if (!_env || !s || !i)
		return (NULL);
	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	if (s[*i] == '$' && ft_strchr("$#*@012345678?9?_!+-", s[*i + 1])
		&& (s[*i + 2] == '\0' || ft_strchr(" \t\v\r\f", s[*i + 2])))
		special_char1(&s1, s, i);
	else if (s[*i] == '$' && s[*i + 1] >= '0' && s[*i + 1] <= '9')
		special_char2(_env, &s1, s, i);
	else
		special_char3(_env, &s1, s, i);
	return (s1);
}

void	check(char c1, char c2)
{
	if ((c1 == '\'' || c1 == '\"') && ft_strchr("<|> \t\v\r\f", c2))
		g_var.flag = 1;
}
