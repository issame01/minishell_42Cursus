/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:37:38 by osabir            #+#    #+#             */
/*   Updated: 2023/08/04 18:17:46 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_token_herdo(t_link **cmd, char *s, int *i)
{
	if (!i || !s)
		return ;
	*i += 1;
	ft_tokenizer_cmd(cmd, ft_strdup("<<"), HERDQ);
	*i += 1;
	while (s[*i] && ft_strchr(" \t\v\r\f", s[*i]))
		*i += 1;
	ft_delimiter(cmd, s, i);
	if (s[*i] != '\'' && s[*i] != '\"')
		*i -= 1;
}

char	*ft_deli_duble_singl(char *s, int *i, int c)
{
	char	*s1;

	if (!s || !i || !c)
		return (NULL);
	g_var.herd_expand = 1;
	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	if (s[*i] == c)
		*i += 1;
	while (s[*i])
	{
		if (s[*i] == c)
			break ;
		s1 = ft_charjoin(s1, s[*i]);
		*i += 1;
	}
	return (s1);
}

char	*ft_delimiter1(char *s, int *i)
{
	char	*s1;

	s1 = ft_strdup("");
	if (!s)
		return (NULL);
	while (s[*i] && !ft_strchr("<|> \t\v\r\f", s[*i]))
	{
		if (s[*i] == '$' && (ft_strchr("\"\'", s[*i + 1])))
			*i += 1;
		if (s[*i] == '\'' || s[*i] == '\"')
		{
			s1 = ft_strjoin(s1, ft_deli_duble_singl(s, i, s[*i]));
			if ((s[*i] == '\"' || s[*i] == '\'') && ft_strchr("<|>", s[*i + 1]))
				break ;
		}
		else
		{
			if (ft_strchr(" \t\v\r\f<|>", s[*i] || s[*i] == '\0'))
				break ;
			s1 = ft_charjoin(s1, s[*i]);
		}
		*i += 1;
	}
	return (s1);
}

void	ft_delimiter(t_link **cmd, char *s, int *i)
{
	char	*s1;
	int		flag;

	if (!s || !i)
		return ;
	flag = 0;
	g_var.herd_expand = 0;
	s1 = ft_delimiter1(s, i);
	ft_tokenizer_cmd(cmd, s1, DELIMITER);
}
