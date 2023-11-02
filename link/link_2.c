/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:39:56 by osabir            #+#    #+#             */
/*   Updated: 2023/08/04 15:58:16 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

char	*ft_duble1(t_env **_env, char *s, char *s1, int *i)
{
	if (!_env || !s || !i)
		return (NULL);
	while (s[*i])
	{
		if (s[*i] == '$' && !ft_isalnum(s[*i + 1]))
		{
			s1 = ft_charjoin(s1, s[*i]);
			*i += 1;
		}
		if (s[*i] == '$')
			s1 = ft_strjoin(s1, ft_expandvar(_env, s, i));
		else
		{
			if (s[*i] == '\"')
				break ;
			s1 = ft_charjoin(s1, s[*i]);
			*i += 1;
		}
	}
	return (s1);
}

char	*ft_duble(t_env **_env, char *s, int *i)
{
	char	*s1;

	if (!_env || !s || !i)
		return (NULL);
	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	if (s[*i] == '\"')
		*i += 1;
	s1 = ft_duble1(_env, s, s1, i);
	return (s1);
}

void	ft_size_sg(char **s1, char *s, int *i)
{
	*s1 = ft_charjoin(*s1, s[*i]);
	*i += 1;
}

char	*ft_token_singel_quotes1(t_env **_env, char *s, char *s1, int *i)
{
	if (!_env || !s || !i)
		return (NULL);
	while (s[*i] && !ft_strchr(" \t\v\r\f", s[*i] && g_var.flag == 0))
	{
		if (s[*i] == '\"')
		{
			s1 = ft_strjoin(s1, ft_duble(_env, s, i));
			check(s[*i], s[*i + 1]);
		}
		else if (s[*i] == '\'')
		{
			s1 = ft_strjoin(s1, ft_sing(s, i));
			check(s[*i], s[*i + 1]);
			*i += 1;
		}
		else if (s[*i] == '$')
			s1 = ft_strjoin(s1, ft_expandvar(_env, s, i));
		else if (ft_strchr("<|>", s[*i]))
			break ;
		else
			ft_size_sg(&s1, s, i);
	}
	return (s1);
}

void	ft_token_singel_quotes(t_link **cmd, t_env **_env, char *s, int *i)
{
	char	*s1;

	if (!_env || !s || !i)
		return ;
	s1 = ft_strdup("");
	if (!s1)
		return ;
	g_var.flag = 0;
	s1 = ft_token_singel_quotes1(_env, s, s1, i);
	ft_tokenizer_cmd(cmd, s1, SIGQ_STR);
}
