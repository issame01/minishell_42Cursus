/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:18:19 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 03:57:44 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*ft_strdup2(char *s1)
{
	char	*dup;
	int		i;
	int		size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	dup = malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		malloc_exit();
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	add_to_bottom(t_env *env, t_env *new)
{
	while (env->next)
	{
		if (ft_strcmp(env->key, new->key))
			return ;
		env = env->next;
	}
	if (ft_strcmp(env->key, new->key))
		return ;
	env->next = new;
}

char	*get_value(const char *s)
{
	unsigned int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == '=')
			return ((char *)s + (i +1));
		i++;
	}
	return (NULL);
}
