/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:09:48 by osabir            #+#    #+#             */
/*   Updated: 2023/08/04 15:31:00 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	skyp(char *s, int *i, int *flag)
{
	if (!s || !i || !flag)
		return ;
	while (s[*i] && ft_strchr(" \t\v\r\f", s[*i]))
		*i += 1;
	if (s[*i] == '\0')
		*flag += 1;
}

void	ft_syntax_error1(char *s, int *flag, int *i)
{
	if (!s || !flag || !i)
		return ;
	if (s[*i] == '>' && s[*i + 1] == '>')
		ft_append(s, flag, i);
	else if (s[*i] == '<' && s[*i + 1] == '<')
		ft_herdo(s, flag, i);
	else if (s[*i] == '>')
		ft_redi_output(s, flag, i);
	else if (s[*i] == '<')
		ft_redi_input(s, flag, i);
	else if (s[*i] == '\"')
		ft_duble_quotes(s, flag, i);
	else if (s[*i] == '\'')
		ft_singel_quotes(s, flag, i);
	else if (s[*i] == '$')
		ft_doller_varble(s, flag, i);
	else
		*i += 1;
}

void	ft_syntax_error(char *s, int *flag)
{
	int	i;

	if (!s || !flag)
		return ;
	i = 0;
	skyp(s, &i, flag);
	if (*flag == 0)
		check_pipe(s, flag);
	while (s[i] && *(flag) == 0)
		ft_syntax_error1(s, flag, &i);
}
