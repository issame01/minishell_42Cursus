/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:05 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 23:40:27 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_cd_tool(char *path, t_env *env)
{
	char	*buf;
	int		size;
	char	*pwd;

	buf = NULL;
	size = 0;
	pwd = getcwd(buf, size);
	if (chdir(path) == 0)
	{
		if (!pwd)
			perror("cd: getcwd: cannot access parent directories");
		else
		{
			change_a_var_in_env(&env, "OLDPWD", pwd);
			change_a_var_in_env(&env, "PWD", getcwd(buf, size));
		}
	}
	else
	{
		free(pwd);
		printf("cd: %s: No such file or directory\n", path);
		g_var.exit_status = 1;
	}
}

void	ft_cd(char *path, t_env *env)
{
	char	*home_dir;

	if (!env)
		return ;
	g_var.exit_status = 0;
	if (!path)
	{
		home_dir = get_path(env, "HOME");
		if (chdir(home_dir) != 0)
		{
			write(2, "minishell_ogs: cd: HOME not set\n", 32);
			g_var.exit_status = 1;
		}
		free(home_dir);
	}
	else
	{
		if (ft_strcmp(path, "-"))
			ft_putendl_fd("minishel_ogs: '-' does not work", 2);
		else if (ft_strcmp(path, "~"))
			ft_putendl_fd("minishel_ogs: '~' does not work", 2);
		else
			ft_cd_tool(path, env);
	}
}
