/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:43:53 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 02:44:30 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_tokenizer1(t_link **cmd, t_env **env, char *s, int *i)
{
	if (!env || !s || !i)
		return ;
	if (s[*i] == '<' && s[*i + 1] == '<')
		ft_token_herdo(cmd, s, i);
	else if (s[*i] == '>' && s[*i + 1] == '>')
		ft_token_append(cmd, i);
	else if (s[*i] == '>')
		ft_token_redi_output(cmd, i);
	else if (s[*i] == '<')
		ft_token_redi_input(cmd, i);
	else if (s[*i] == 39)
		ft_token_singel_quotes(cmd, env, s, i);
	else if (s[*i] == '"')
		ft_token_duble_quotes(cmd, env, s, i);
	else if (s[*i] == '|')
		ft_token_pipe(cmd, i);
	else if (s[*i] == '$')
		ft_token_doller(cmd, env, s, i);
	else if (!ft_strchr("\'\">|< \t\v\r\f", s[*i]))
		ft_token_word(cmd, env, s, i);
}

void	ft_tokenizer(t_link **cmd, t_env **env, char *s)
{
	int				i;

	i = 0;
	if (!env || !s)
		return ;
	while (s[i])
	{
		ft_tokenizer1(cmd, env, s, &i);
		if (s[i] == '\0')
			break ;
		i++;
	}
}

void	ft_word(char **s1, char *s, int *i)
{
	*s1 = ft_charjoin(*s1, s[*i]);
	*i += 1;
}

char	*ft_token_word1(t_env **_env, char *s, int *i)
{
	char	*s1;

	s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	while (s[*i] && !ft_strchr("<|> \t\v\r\f", s[*i]))
	{
		if (s[*i] == '\"')
		{
			s1 = ft_strjoin(s1, ft_duble(_env, s, i));
			if (s[*i] == '\"' && ft_strchr("<|> \t\v\r\f", s[*i + 1]))
				break ;
		}
		else if (s[*i] == '\'')
		{
			s1 = ft_strjoin(s1, ft_sing(s, i));
			if (s[*i] == '\'' && ft_strchr("<|> \t\v\r\f", s[*i + 1]))
				break ;
		}
		else if (s[*i] == '$')
			s1 = ft_strjoin(s1, ft_expandvar(_env, s, i));
		else
			ft_word(&s1, s, i);
	}
	return (s1);
}

void	ft_token_word(t_link **cmd, t_env **_env, char *s, int *i)
{
	char	*s1;

	if (!_env || !s || !i)
		return ;
	s1 = ft_token_word1(_env, s, i);
	if (s[*i] != '\'' && s[*i] != '\"')
		*i -= 1;
	ft_tokenizer_cmd(cmd, s1, WORD);
}
