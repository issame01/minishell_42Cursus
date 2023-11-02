/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:09 by idryab            #+#    #+#             */
/*   Updated: 2023/08/06 22:15:19 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_there_n(char *str)
{
	int		i;
	int		nflag;

	i = 1;
	nflag = 1;
	if (str[0] == '-')
	{
		if (str[1] == '\0')
			return (0);
		while (str[i])
		{
			if (str[i] != 'n')
				nflag = 0;
			i++;
		}
	}
	else
		nflag = 0;
	return (nflag);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	ft_echo(char **cmd)
{
	int	i;
	int	notcheck;

	i = 1;
	notcheck = 0;
	g_var.exit_status = 0;
	if (!cmd[1] || cmd[1][0] == '\0')
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	while (cmd[i])
	{
		if ((cmd[i] && notcheck == 1) || is_there_n(cmd[i]) == 0)
		{
			if (notcheck == 1)
				ft_putchar_fd(' ', STDOUT_FILENO);
			ft_putstr_fd(cmd[i], STDOUT_FILENO);
			notcheck = 1;
		}
		i++;
	}
	if (is_there_n(cmd[1]) == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
