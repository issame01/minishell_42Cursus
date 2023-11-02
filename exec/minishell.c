/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:38:52 by idryab            #+#    #+#             */
/*   Updated: 2023/08/09 17:16:47 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_if_builtins(t_cmd *data)
{
	char	*cmd;

	if (!data)
		return (0);
	cmd = tolower_buil(data->cmd[0]);
	if (ft_strcmp(cmd, "echo"))
		return (1);
	else if (ft_strcmp(cmd, "cd"))
		return (1);
	else if (ft_strcmp(cmd, "pwd"))
		return (1);
	else if (ft_strcmp(cmd, "env"))
		return (1);
	else if (ft_strcmp(cmd, "export"))
		return (1);
	else if (ft_strcmp(cmd, "unset"))
		return (1);
	else if (ft_strcmp(cmd, "exit"))
		return (1);
	else
		return (0);
}

void	ft_no_cmd_with_redirection(t_cmd *data)
{
	if (data->file_input == -1 || data->file_output == -1)
	{
		ft_putendl_fd(ERROR_FILE, STDERR_FILENO);
		g_var.exit_status = 1;
	}
}

void	final_func(t_cmd **_data, t_env **envire)
{
	int		num_cmd;
	t_cmd	*data;
	int		stdout_cpy;

	data = *_data;
	if (!data)
		return ;
	if (data->cmd == NULL)
	{
		ft_no_cmd_with_redirection(data);
		return ;
	}
	num_cmd = count_cmds(data);
	if (data->next == NULL && check_if_builtins(data))
	{
		stdout_cpy = redirect_stdout_n_save_cpy(data);
		run_builtins(data, envire);
		if (stdout_cpy == 0)
			return ;
		dup2(stdout_cpy, STDOUT_FILENO);
		close(stdout_cpy);
		return ;
	}
	else
		run_process(data, num_cmd, envire);
}
