/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:35 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 03:53:59 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env_null(t_env **env)
{
	char	*buf;
	char	*pwd;
	int		size;
	int		shl;

	buf = NULL;
	size = 0;
	shl = 1;
	g_var.ignore = 1;
	g_var.fre = 0;
	pwd = getcwd(buf, size);
	ft_link_env1(env, "PWD", pwd);
	free(pwd);
	shl++;
	ft_link_env1(env, "SHLVL", "1");
	ft_link_env1(env, "_", "/usr/bin/env");
}

void	ft_link_env1(t_env **_env, char *_key, char *_value)
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
