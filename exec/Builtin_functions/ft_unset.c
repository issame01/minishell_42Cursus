/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:35 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 02:22:39 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	unset_identifier(char *key)
{
	int	i;

	i = 0;
	if (key[0] >= '0' && key[0] <= '9')
	{
		printf("minishell: unset: `%s': not a valid identifier\n", key);
		return (0);
	}
	while (key[i])
	{
		if (!(key[i] == '_') && !(key[i] >= 'a' && key[i] <= 'z')
			&& !(key[i] >= 'A' && key[i] <= 'Z')
			&& !(key[i] >= '0' && key[i] <= '9'))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", key);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_unset(t_env *data, char *unseter)
{
	int	i;

	i = 0;
	if (!unseter || unset_identifier(unseter) == 0)
	{
		g_var.exit_status = 1;
		return ;
	}
	while (data != NULL)
	{
		if (ft_strcmp(data->key, unseter))
		{
			free(data->key);
			data->key = NULL;
			free(data->value);
			data->value = NULL;
			break ;
		}
		data = data->next;
	}
	return ;
}
