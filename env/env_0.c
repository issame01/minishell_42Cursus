/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:48:35 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 03:53:37 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_link_env(t_env **_env, char *_key, char *_value)
{
	t_env	*env;
	t_env	*path;

	if (!_key || !_value)
		return ;
	env = malloc(sizeof(t_env));
	if (!env)
		malloc_exit();
	env->key = ft_strdup(_key);
	env->value = ft_strdup(_value);
	free(_key);
	free(_value);
	env->next = NULL;
	if (*_env == NULL)
	{
		*_env = env;
		return ;
	}
	path = *_env;
	while (path->next != NULL)
		path = path->next;
	path->next = env;
}

void	ft_take_to_env(t_env **env, char *s)
{
	char	*s1;
	char	*s2;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (s[i] == '=')
			break ;
		i++;
	}
	s1 = ft_substr(s, 0, i);
	j = i + 1;
	while (s[i])
		i++;
	s2 = ft_substr(s, j, (i - j));
	ft_link_env(env, s1, s2);
}

void	ft_take_env(t_env **env, char **_env)
{
	int	i;

	i = 0;
	if (!_env || *_env == NULL)
		return ;
	while (_env[i])
	{
		ft_take_to_env(env, _env[i]);
		i++;
	}
}

void	chlvl1(t_env **_env)
{
	t_env	*env;
	int		input;

	env = *_env;
	while (env)
	{
		if (ft_strcmp(env->key, "SHLVL"))
		{
			input = ft_atoi(env->value);
			free(env->value);
			if (input < 0)
				env->value = ft_strdup("0");
			if (input + 1 <= 999)
				env->value = ft_itoa(input + 1);
			else if (input + 1 == 1000)
				env->value = ft_strdup("");
			else if (input > 1000)
				env->value = ft_itoa(1);
			return ;
		}
		env = env->next;
	}
	env = *_env;
	ft_link_env(_env, ft_strdup("SHLVL"), ft_strdup("1"));
}

void	chlvl(t_env **_env)
{
	t_env	*env;

	env = *_env;
	while (env)
	{
		if (ft_strcmp(env->key, "!@#$"))
		{
			chlvl1(_env);
			return ;
		}
		env = env->next;
	}
	env = *_env;
	ft_link_env(_env, ft_strdup("!@#$"), ft_strdup("1"));
}
