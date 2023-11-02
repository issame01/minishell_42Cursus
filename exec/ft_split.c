/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:44:19 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 03:55:53 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	ft_wordc(const char *str, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			counter++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (counter);
}

static char	**free_all(char **s, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i && s[j] != NULL)
	{
		free(s[j]);
		s[j] = NULL;
		j++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **spliter, size_t wc)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	while (i < wc)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		spliter[i] = ft_substr(s, start, end - start);
		if (!spliter[i])
			return (free_all(spliter, i));
		start = end;
		i++;
	}
	*(spliter + i) = NULL;
	return (spliter);
}

char	**ft_split(char const *s, char c)
{
	char	**spliter;
	size_t	wc;

	if (!s)
		return (0);
	wc = ft_wordc(s, c);
	spliter = malloc((wc + 1) * sizeof(char *));
	if (!spliter)
		malloc_exit();
	return (ft_fill(s, c, spliter, wc));
}
