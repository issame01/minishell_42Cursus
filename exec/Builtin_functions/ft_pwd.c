/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:29 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 02:22:36 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_env **envire)
{
	char	*pwd;
	char	*buf;
	size_t	size;

	size = 0;
	buf = NULL;
	pwd = getcwd(buf, size);
	if (!pwd)
		pwd = get_path(*envire, "PWD");
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return ;
}
