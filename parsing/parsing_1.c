/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:14:14 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 13:58:18 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	globle_error(int *flag)
{
	ft_putendl_fd("syntax error.", STDERR_FILENO);
	*flag += 1;
	g_var.exit_status = 258;
}

void	ft_redi_output(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	*i += 1;
	while (s[(*i)] && ft_strchr(" \t\v\r\f", s[*i]) && *flag == 0)
		*i += 1;
	if (s[(*i)] == '|' || s[(*i)] == '<'
		|| s[(*i)] == '>' || s[*i] == '\0')
		globle_error(flag);
}

void	ft_redi_input(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	*i += 1;
	while (s[(*i)] && ft_strchr(" \t\v\r\f", s[*i]) && *flag == 0)
		*i += 1;
	if (s[(*i)] == '|' || s[(*i)] == '<'
		|| s[(*i)] == '>' || s[*i] == '\0')
		globle_error(flag);
}

void	ft_append(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	*i += 2;
	if (s[*i] == '\0')
	{
		globle_error(flag);
		return ;
	}
	while (s[(*i)] && ft_strchr(" \t\v\r\f", s[*i]) && *flag == 0)
		*i += 1;
	if (s[(*i)] == '|' || s[(*i)] == '<'
		|| s[(*i)] == '>' || s[(*i)] == '\0')
		globle_error(flag);
}

void	ft_herdo(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	*i += 2;
	if (s[*i] == '\0')
	{
		globle_error(flag);
		return ;
	}
	while (s[(*i)] && ft_strchr(" \t\v\r\f", s[*i]) && *flag == 0)
		*i += 1;
	if (s[(*i)] == '|' || s[(*i)] == '<'
		|| s[(*i)] == '>' || s[(*i)] == '\0')
		globle_error(flag);
}
