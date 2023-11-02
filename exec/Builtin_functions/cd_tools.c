/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:40:39 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 03:06:08 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_path(t_env *env, char *var)
{
	char	*path;

	path = NULL;
	while (env->next != NULL)
	{
		if (ft_strcmp(env->key, var))
		{
			path = ft_strdup(env->value);
			break ;
		}
		env = env->next;
	}
	return (path);
}

void	change_a_var_in_env(t_env **env, char *key, char *value)
{
	if (!value)
		return ;
	while (*env)
	{
		if (ft_strcmp((*env)->key, key))
		{
			free((*env)->value);
			(*env)->value = ft_strdup(value);
			free(value);
			return ;
		}
		*env = (*env)->next;
	}
	free(value);
	return ;
}

int	size_b_three(char *pwd)
{
	int	i;
	int	slash;

	i = 0;
	slash = 0;
	while (pwd[i])
	{
		if (pwd[i] == '/')
			slash++;
		if (slash == 3)
			return (i);
		i++;
	}
	return (0);
}
