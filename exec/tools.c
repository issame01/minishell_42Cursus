/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:20:12 by idryab            #+#    #+#             */
/*   Updated: 2023/08/09 17:15:47 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_completed_cmd(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = 0;
	i = 0;
	if (!path)
		return (NULL);
	path_cmd = ft_strjoin2("/", cmd);
	while (path[i])
	{
		tmp = ft_strjoin2(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
			return (free(path_cmd), tmp);
		close(fd);
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
}

void	add_back(t_env **env, t_env *new)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_func(char **input)
{
	int	i;

	i = 0;
	while (input[i] != NULL)
	{
		free(input[i]);
		input[i] = NULL;
		i++;
	}
	free(input);
	input = NULL;
}

int	count_cmds(t_cmd *data)
{
	int	i;

	i = 0;
	if (!data)
		return (0);
	while (data != NULL)
	{
		i++;
		data = data->next;
	}
	return (i);
}

int	redirect_stdout_n_save_cpy(t_cmd *data)
{
	int	stdout_cpy;
	int	check;

	stdout_cpy = dup(STDOUT_FILENO);
	if (data->file_input == -1 || data->file_output == -1)
		return (perror("minishell: "), 0);
	if (data->file_output != -2)
	{
		check = dup2(data->file_output, STDOUT_FILENO);
		close(data->file_output);
	}
	if (data->file_input != -2)
		return (0);
	if (check == -1)
		exit(1);
	return (stdout_cpy);
}
