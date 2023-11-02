/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:44:30 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 01:27:23 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_token_redi_output(t_link **cmd, int *i)
{
	if (!i)
		return ;
	ft_tokenizer_cmd(cmd, ft_strdup(">"), REDI_OUT);
}

void	ft_token_redi_input(t_link **cmd, int *i)
{
	if (!i)
		return ;
	ft_tokenizer_cmd(cmd, ft_strdup("<"), REDI_IN);
}

char	*ft_exit_status(char *s, int *i)
{
	char	*s1;

	if (!s || !i)
		return (NULL);
	s1 = ft_itoa(g_var.exit_status);
	*i += 1;
	return (s1);
}

char	*ft_expandvar(t_env **_env, char *s, int *i)
{
	t_env	*env;
	char	*s1;

	if (!_env || !s || !i)
		return (NULL);
	if (s[*i] == '$' && s[*i + 1] == '?'
		&& (s[*i + 2] == '\0' || ft_strchr("<|>\'\" \t\v\r\f", s[*i + 2])))
		return (ft_exit_status(s, i));
	*i += 1;
	s1 = ft_strdup("");
	env = *_env;
	while (s[*i] != '\0' && !ft_strchr(" \t\v\r\f", s[*i])
		&& (ft_isalnum(s[*i]) || s[*i] == '_'))
	{
		s1 = ft_charjoin(s1, s[*i]);
		*i += 1;
	}
	while (env)
	{
		if (ft_cmp_to_str(s1, env->key))
			if (env->value)
				return (free(s1), ft_strdup(env->value));
		env = env->next;
	}
	return (g_var.null = 1, free(s1), ft_strdup(""));
}

int	mt_line(char *s, int *i)
{
	if (!s || !i)
		return (0);
	if (ft_strchr("\"", s[*i]) \
		&& ft_strchr("\"", s[*i + 1]) \
			&& (s[*i +2] == '\0' || ft_strchr("<|> \t\v\r\f", s[*i + 2])))
		return (1);
	return (0);
}
