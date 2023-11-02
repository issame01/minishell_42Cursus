/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:28:00 by osabir            #+#    #+#             */
/*   Updated: 2023/08/09 13:00:55 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

char	*ft_dubleq1(t_env **_env, char *s, int *flag, int *i)
{
	char	*s1;

	if (!_env || !s || !i || !flag)
		return (NULL);
	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	s1 = ft_strjoin(s1, ft_duble(_env, s, i));
	if (s[*i] == '\"' && ft_strchr("<|> \t\v\r\f", s[*i + 1]))
	{
		*flag += 1;
		return (s1);
	}
	*i += 1;
	return (s1);
}

char	*ft_dubleq2(char *s, int *flag, int *i)
{
	char	*s1;

	if (!s || !i || !flag)
		return (NULL);
	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	s1 = ft_strjoin(s1, ft_sing(s, i));
	if (s[*i] == '\'' && ft_strchr("<|> \t\v\r\f", s[*i + 1]))
	{
		*flag += 1;
		return (s1);
	}
	*i += 1;
	return (s1);
}

void	ft_dubleq3(char **s1, char *s, int *flag, int *i)
{
	if (!s || !i || !flag)
		return ;
	if (ft_strchr("<|>", s[*i]))
	{
		*flag += 1;
		return ;
	}
	*s1 = ft_charjoin(*s1, s[*i]);
	*i += 1;
}

void	ft_dubleq4(char **s1, char *s, int *flag, int *i)
{
	if (!s || !i || !flag)
		return ;
	*s1 = ft_charjoin(*s1, s[*i]);
	*i += 1;
}

void	ft_token_duble_quotes(t_link **cmd, t_env **_env, char *s, int *i)
{
	char	*s1;
	int		flag;

	if (!_env || !s || !i)
		return ;
	s1 = ft_strdup("");
	if (!s1)
		return ;
	flag = 0;
	while (s[*i] && !ft_strchr(" \t\v\r\f", s[*i]) && flag == 0)
	{
		if (mt_line(s, i))
			ft_dubl_q_only(i, &flag);
		else if (s[*i] == '\"')
			s1 = ft_strjoin(s1, ft_dubleq1(_env, s, &flag, i));
		else if (s[*i] == '\'')
			s1 = ft_strjoin(s1, ft_dubleq2(s, &flag, i));
		else if (s[*i] == '$' && s[*i + 1] == '"')
			ft_dubleq4(&s1, s, &flag, i);
		else if (s[*i] == '$')
			s1 = ft_strjoin(s1, ft_expandvar(_env, s, i));
		else
			ft_dubleq3(&s1, s, &flag, i);
	}
	ft_tokenizer_cmd(cmd, s1, DUBQ_STR);
}
