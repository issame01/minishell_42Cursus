/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_n_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 02:23:42 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 22:28:54 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dup_exit(void)
{
	ft_putendl_fd("dup has failed", STDERR_FILENO);
	exit(1);
}

void	close_fds(int **fds, int num_cmd)
{
	int	index;

	index = 0;
	while (index < num_cmd - 1)
	{
		close(fds[index][0]);
		close(fds[index][1]);
		index++;
	}
}

void	err_n_exit(char	*file)
{
	int	fd;

	fd = access(file, F_OK);
	if (fd == -1)
	{
		perror("minishell: ");
		exit(127);
	}
	fd = access(file, X_OK);
	if (fd == -1)
	{
		perror("minishell: ");
		exit(126);
	}
}

void	malloc_exit(void)
{
	ft_putendl_fd("Malloc failed", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
