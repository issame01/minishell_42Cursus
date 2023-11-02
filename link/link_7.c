/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:32:18 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 23:02:22 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_token_doller1(t_link **cmd, t_env **_env, char *s, int *i)
{
	char	*s1;

	if (!_env || !s || !i)
		return ;
	s1 = ft_strdup("");
	if (!s1)
		return ;
	while (s[*i] && !ft_strchr(" \t", s[*i]) && s[*i] != '\0')
	{
		if (s[*i] == '\"')
			*i += 1;
		else if (s[*i] == '\'')
			s1 = ft_strjoin(s1, ft_sing(s, i));
		else if (s[*i] == '$')
			s1 = ft_strjoin(s1, ft_expandvar(_env, s, i));
		else
		{
			s1 = ft_charjoin(s1, s[*i]);
			*i += 1;
		}
	}
	ft_tokenizer_cmd(cmd, s1, ENV_VAR);
}

void	ft_token_doller(t_link **cmd, t_env **_env, char *s, int *i)
{
	char	*s1;

	if (!_env || !s || !i) 
		return ;
	s1 = ft_strdup("");
	if (!s1)
		return ;
	if (s[*i] == '$' && (ft_strchr(" \t\v\r\f", s[*i + 1]) || s[*i + 1] == '\0'))
	{
		g_var.fre = 1;
		ft_tokenizer_cmd(cmd, "$", ENV_SPSH);
		free(s1);
		return ;
	}
	else if (s[*i] == '$' && ft_strchr("$#*@012345678?9!-", s[*i + 1])
		&& (ft_strchr("\'\" \t\v\r\f", s[*i + 2]) || s[*i + 2] == '\0'))
	{
		s1 = ft_strjoin(s1, special_char(_env, s, i));
		ft_tokenizer_cmd(cmd, s1, ENV_SPSH);
		return ;
	}
	free(s1);
	ft_token_doller1(cmd, _env, s, i);
}

void	ft_token_pipe(t_link **cmd, int *i)
{
	if (!i)
		return ;
	ft_tokenizer_cmd(cmd, ft_strdup("|"), PIPE);
}

char	*ft_sing(char *s, int *i)
{
	char	*s1;

	if (!s || !i)
		return (NULL);
	g_var.herd_expand = 1;
	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	if (s[*i] == '\'')
		*i += 1;
	while (s[*i])
	{
		if (s[*i] == '\'')
			break ;
		s1 = ft_charjoin(s1, s[*i]);
		*i += 1;
	}
	return (s1);
}

void	ft_dubl_q_only(int *i, int *flag)
{
	*i += 1;
	*flag += 1;
}
