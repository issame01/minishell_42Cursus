/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:21:05 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 03:56:41 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_size(t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	*ft_strjoin5(char *s1, char *s2)
{
	char	*str;
	int		j;
	int		o;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		malloc_exit();
	j = 0;
	o = 0;
	while (s1[j] != '\0')
		str[o++] = s1[j++];
	j = 0;
	str[o++] = '=';
	while (s2[j] != '\0')
		str[o++] = s2[j++];
	str[o] = '\0';
	return (str);
}

char	**join_env(t_env *env)
{
	char	**joined_env;
	int		i;
	int		size;

	i = 0;
	size = count_size(env);
	joined_env = malloc(sizeof(char *) * (size + 1));
	if (!joined_env)
		return (NULL);
	ft_void(joined_env, size + 1);
	while (env != NULL)
	{
		if (env->key && !env->value)
		{
			env->value = ft_strdup("");
			joined_env[i++] = ft_strjoin5(env->key, env->value);
		}
		else if (env->key && env->value)
			joined_env[i++] = ft_strjoin5(env->key, env->value);
		env = env->next;
	}
	return (joined_env);
}
