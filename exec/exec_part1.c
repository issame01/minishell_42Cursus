/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:38:45 by idryab            #+#    #+#             */
/*   Updated: 2023/08/09 16:22:31 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	childprocess(int num_cmd, t_cmd *data, t_env **env, int **fds)
{
	signal(SIGQUIT, sig_handler);
	if (data->file_input == -1 || data->file_output == -1)
	{
		ft_putendl_fd("minishell: No such file or directory", STDERR_FILENO);
		g_var.exit_status = 1;
		exit(1);
	}
	if (data->file_output != -2)
		if (dup2(data->file_output, STDOUT_FILENO) == -1)
			dup_exit();
	if (data->file_input != -2)
		if (dup2(data->file_input, STDIN_FILENO) == -1)
			dup_exit();
	close_fds(fds, num_cmd);
	if (run_builtins(data, env))
		exit(0);
	else
		run_execv(data->cmd, *env);
	exit(0);
}

static int	**create_pipes(int num_pipes)
{
	int	**fds;
	int	index;

	index = 0;
	fds = malloc(sizeof(int *) * (num_pipes));
	if (!fds)
		malloc_exit();
	while (index < num_pipes)
	{
		fds[index] = malloc(sizeof(int) * 2);
		if (!fds[index])
			malloc_exit();
		if (pipe(fds[index++]) == -1)
		{
			ft_putendl_fd("Pipe: too many open files in system", STDERR_FILENO);
			exit(1);
		}
	}
	return (fds);
}

static int	**redirect_pipes_n_files(int num_cmd, \
		int cmd_index, t_cmd *data, int **fds)
{
	if (num_cmd -1 != 0)
	{
		if (cmd_index == 0 && data->file_output == -2)
			data->file_output = fds[cmd_index][1];
		else if (cmd_index == num_cmd - 1 && data->file_input == -2)
			data->file_input = fds[cmd_index -1][0];
		else if (cmd_index > 0 && cmd_index < num_cmd - 1)
		{
			if (data->file_input == -2)
				data->file_input = fds[cmd_index -1][0];
			if (data->file_output == -2)
				data->file_output = fds[cmd_index][1];
		}
	}
	return (fds);
}

static void	wait_processes(int proce_num, pid_t pid_tmp)
{
	int	status;

	waitpid(pid_tmp, &status, 0);
	if (WIFEXITED(status))
		g_var.exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_var.exit_status = WTERMSIG(status) + 128;
	while (proce_num--)
		waitpid(-1, NULL, 0);
}

void	run_process(t_cmd *data, int num_cmd, t_env **env)
{
	pid_t	pid;
	int		**fds;
	int		cmd_index;

	fds = create_pipes(num_cmd - 1);
	cmd_index = 0;
	while (data != NULL)
	{
		fds = redirect_pipes_n_files(num_cmd, cmd_index, data, fds);
		pid = fork();
		if (pid == 0)
			childprocess(num_cmd, data, env, fds);
		if (pid == -1)
		{
			ft_putendl_fd("fork has failed to create a process", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		data = data->next;
		cmd_index++;
	}
	close_fds(fds, num_cmd);
	free_pipes((void **)fds, num_cmd -1);
	wait_processes(num_cmd, pid);
}
