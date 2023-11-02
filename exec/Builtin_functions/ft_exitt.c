/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:55:54 by idryab            #+#    #+#             */
/*   Updated: 2023/08/09 13:09:35 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_isdigit2(char *str, long tmp)
{
	int	i;

	i = 0;
	if (tmp >= LONG_MAX || tmp <= LONG_MIN)
	{
		ft_putendl_fd("exit: numericcc arguments required", STDERR_FILENO);
		exit(255);
	}
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_exitt(t_cmd *data)
{
	long long	tmp;

	if (data->cmd[1])
	{
		tmp = ft_atoi(data->cmd[1]);
		if (ft_isdigit2(data->cmd[1], tmp))
		{
			ft_putendl_fd("exit: numeric arguments required", STDERR_FILENO);
			exit(255);
		}
		else if (data->cmd[2] != NULL)
		{
			ft_putendl_fd("exit: too many argumentss", STDERR_FILENO);
			exit(1);
		}
		write(1, "exit\n", 5);
		exit(tmp);
	}
	else
	{
		write(1, "exit\n", 5);
		exit(0);
	}
}
