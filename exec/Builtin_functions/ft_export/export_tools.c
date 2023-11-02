/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:16:19 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 03:57:35 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	if_not_arg(t_env *env)
{
	while (env)
	{
		if (!env->value && env->key)
			printf("declare -x %s\n", env->key);
		else if (env->key && env->value && !ft_strcmp(env->key, "!@#$"))
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
}

int	check_identifier(char *key)
{
	int	i;

	i = 0;
	if (key[0] >= '0' && key[0] <= '9')
	{
		printf("minishell: export: `%s': not a valid identifier\n", key);
		return (0);
	}
	while (key[i])
	{
		if (!(key[i] == '_') && !(key[i] >= 'a' && key[i] <= 'z')
			&& !(key[i] >= 'A' && key[i] <= 'Z')
			&& !(key[i] >= '0' && key[i] <= '9'))
		{
			printf("minishell: export: `%s': not a valid identifier\n", key);
			return (0);
		}
		i++;
	}
	return (1);
}

int	equal_after_plus(char *key)
{
	int	i;

	i = 0;
	if (key[0] == '\0' && !g_var.null)
	{
		printf("minishell: export: `%s': not a valid identifier\n", key);
		return (0);
	}
	while (key[i])
	{
		if (key[0] == '=' || (key[i] == '+' && key[i +1] != '='))
		{
			printf("minishell: export: `%s': not a valid identifier\n", key);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*rm_plus(char *key)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(key) + 1);
	if (!tmp)
		malloc_exit();
	while (key[i])
	{
		if (key[i] == '+')
			break ;
		tmp[i] = key[i];
		i++;
	}
	tmp[i] = '\0';
	free(key);
	return (tmp);
}
