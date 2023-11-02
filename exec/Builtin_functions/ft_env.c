/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:14 by idryab            #+#    #+#             */
/*   Updated: 2023/08/09 13:43:23 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(t_env *env)
{
	while (env)
	{
		if (env->value != NULL && !ft_strcmp(env->key, "!@#$"))
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
