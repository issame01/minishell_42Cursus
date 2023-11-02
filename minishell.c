/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:21:53 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 21:24:05 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig_nal)
{
	if (sig_nal == SIGINT && g_var.flag_herd == 1)
	{
		g_var.flag_herd = 0;
		g_var.stop = 1;
		close(STDIN_FILENO);
		return ;
	}
	if (waitpid(-1, NULL, WNOHANG) == 0)
		return ;
	else if (sig_nal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_main1(t_cmd **cmd, t_link **link, t_env **env, char *input)
{
	g_var.stop = 0;
	ft_tokenizer(link, env, input);
	final_list(cmd, link, env);
	if (g_var.stop == 0)
		final_func(cmd, env);
	free_link(link);
	free_cmd(cmd);
}

void	ft_exit(void)
{
	printf("exit\n");
	exit(0);
}

void	ft_main(t_env **env)
{
	t_link	*link;
	t_cmd	*cmd;
	char	*input;
	int		flag;

	cmd = NULL;
	link = NULL;
	flag = 0;
	while (1)
	{
		g_var.null = 0;
		signal(SIGQUIT, handler);
		signal(SIGINT, handler);
		input = ft_strtrim(readline("minishell$ "), " \t\v\r\f");
		if (input == NULL)
			ft_exit();
		if (*input)
			add_history(input);
		ft_syntax_error(input, &flag);
		if (flag == 0)
			ft_main1(&cmd, &link, env, input);
		flag = 0;
		free(input);
	}
}

int	main(int ac, char **av, char **_env)
{
	t_env	*env; 
	int		flag;

	env = NULL;
	flag = 0;
	ign(ac, av);
	ft_take_env(&env, _env);
	if (!env)
		ft_env_null(&env);
	chlvl(&env);
	ft_main(&env);
	free_env(env); 
	return (0);
}
