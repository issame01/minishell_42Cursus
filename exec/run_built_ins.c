/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_built_ins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:18:31 by idryab            #+#    #+#             */
/*   Updated: 2023/08/06 21:55:39 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*tolower_buil(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] +32;
		i++;
	}
	return (str);
}

int	is_in_envire(t_env *envire, char *var)
{
	while (envire)
	{
		if (ft_strcmp(envire->value, var))
			return (1);
		envire = envire->next;
	}
	return (0);
}

int	function2(char *str, t_env **envire)
{
	char	**allinone;
	int		i;

	i = 0;
	allinone = NULL;
	if (ft_strchr(str, ' '))
		allinone = ft_split(str, ' ');
	if (allinone == NULL || !is_in_envire(*envire, str))
		return (0);
	while (allinone[i] != NULL)
		ft_export(*envire, allinone[i++]);
	return (free_func(allinone), 1);
}

int	run_builtins2(char *cmd, t_cmd *data, t_env **envire)
{
	int	i;

	i = 1;
	if (ft_strcmp(cmd, "export"))
	{
		while (data->cmd[i] != NULL)
			ft_export(*envire, data->cmd[i++]);
		if (data->cmd[1] == NULL)
			ft_export(*envire, data->cmd[1]);
		return (1);
	}
	else if (ft_strcmp(cmd, "unset"))
	{
		while (data->cmd[i] != NULL)
			ft_unset(*envire, data->cmd[i++]);
		return (1);
	}
	return (0);
}

int	run_builtins(t_cmd *data, t_env **envire)
{
	int		i;
	char	*cmd;

	if (!data || !envire)
		return (0);
	i = 1;
	cmd = tolower_buil(data->cmd[0]);
	if (ft_strcmp(cmd, "echo"))
		return (ft_echo(data->cmd), 1);
	else if (ft_strcmp(cmd, "cd"))
		return (ft_cd(data->cmd[1], *envire), 1);
	else if (ft_strcmp(cmd, "pwd"))
		return (ft_pwd(envire), 1);
	else if (ft_strcmp(cmd, "env"))
		return (ft_env(*envire), 1);
	else if (ft_strcmp(cmd, "exit"))
		return (ft_exitt(data), 1);
	else if (run_builtins2(cmd, data, envire))
		return (1);
	else
		return (0);
}
