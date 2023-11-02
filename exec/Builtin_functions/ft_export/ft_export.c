/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:39:21 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 23:44:30 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	add_new_var(t_env *env, char *key, char *value)
{
	t_env	*add;
	int		i;

	i = 0;
	if (g_var.ignore == 1)
	{
		if (ft_strcmp(key, "PATH") && value == NULL)
			value = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	}
	add = malloc(sizeof(t_env));
	if (!add)
		malloc_exit();
	add->key = key;
	add->value = value;
	add->next = NULL;
	if (env)
		add_to_bottom(env, add);
	else
		env = add;
}

static int	is_there_plus(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (key[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

static int	exp_func(t_exp *exp, t_env *env, char *key_value)
{
	if (equal_after_plus(key_value) == 0)
		return (0);
	exp->key1 = ft_split(key_value, '=');
	if (function2(exp->key1[0], &env))
		return (free_func(exp->key1), 0);
	exp->plus = is_there_plus(exp->key1[0]);
	exp->value1 = get_value(key_value);
	exp->rem_plus = rm_plus(exp->key1[0]);
	exp->key1[0] = ft_strdup(exp->rem_plus);
	free(exp->rem_plus);
	if (!exp->key1[0] || exp->key1[0][0] == '\0')
	{
		printf("minishell: export: `%s': not a valid identifier\n",
			exp->key1[0]);
		return (0);
	}
	if (check_identifier(exp->key1[0]) == 0)
	{
		free_func(exp->key1);
		return (0);
	}
	return (1);
}

static int	exp_func2(t_env **env, t_exp exp)
{
	while (*env)
	{
		if (ft_strcmp((*env)->key, exp.key1[0]) && (*env)->value == NULL)
		{
			free((*env)->value);
			(*env)->value = ft_strdup2(exp.value1);
			return (free_func(exp.key1), 1);
		}
		else if (ft_strcmp((*env)->key, exp.key1[0]) && exp.value1 != NULL)
		{
			if (exp.plus == 1)
				exp.value1 = ft_strjoin2((*env)->value, exp.value1);
			exp.tmp = (*env)->value;
			(*env)->value = ft_strdup2(exp.value1);
			free(exp.tmp);
			if (exp.plus == 1)
				free(exp.value1);
			return (free_func(exp.key1), 1);
		}
		else if (ft_strcmp((*env)->key, exp.key1[0]) && exp.value1 == NULL)
			return (free_func(exp.key1), 1);
		*env = (*env)->next;
	}
	return (0);
}

void	ft_export(t_env *env, char *key_value)
{
	t_exp	exp;
	t_env	*temp2;

	g_var.exit_status = 0;
	if (!key_value || g_var.null)
	{
		if_not_arg(env);
		return ;
	}
	if (exp_func(&exp, env, key_value) == 0)
	{
		g_var.exit_status = 1;
		return ;
	}
	temp2 = env;
	if (exp_func2(&env, exp) == 0)
	{
		add_new_var(temp2, ft_strdup2(exp.key1[0]), ft_strdup2(exp.value1));
		free_func(exp.key1);
	}
}
