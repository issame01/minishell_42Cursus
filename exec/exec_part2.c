/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:47:41 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 22:47:03 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_pipes(void **s, int numpipe)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (i < numpipe)
		free(s[i++]);
	free(s);
	s = NULL;
}

void	sig_handler(int sig_num)
{
	(void)sig_num;
	signal(SIGQUIT, SIG_DFL);
}

static void	throw_error(char *err, int fd, char *cmd)
{
	ft_putstr_fd(err, fd);
	ft_putendl_fd(cmd, fd);
	exit(127);
}

void	free_all(char **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free(s[j]);
		s[j] = NULL;
		j++;
	}
	free(s);
	s = NULL;
}

void	run_execv(char **cmds_splitted, t_env *env)
{
	char	**real_path;
	char	*right_cmd;
	char	*env_path;
	char	**joined_env;

	joined_env = NULL;
	joined_env = join_env(env);
	if (ft_strchr(cmds_splitted[0], '/'))
		right_cmd = cmds_splitted[0];
	else
	{
		if (g_var.ignore == 1)
			env_path = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin");
		else
			env_path = get_path(env, "PATH");
		if (!env_path)
			throw_error(ERROR_COMMAD, STDERR_FILENO, cmds_splitted[0]);
		real_path = ft_split(env_path, ':');
		right_cmd = get_completed_cmd(real_path, cmds_splitted[0]);
		free_all(real_path);
		if (!right_cmd || cmds_splitted[0][0] == '\0')
			throw_error("minishell: command not found: ", 2, cmds_splitted[0]);
	}
	if (execve(right_cmd, cmds_splitted, joined_env) == -1)
		err_n_exit(cmds_splitted[0]);
}
