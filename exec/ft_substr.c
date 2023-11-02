/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:39:11 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 03:56:30 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_strdup_sub(const char *s1)
{
	char	*dup;
	int		i;
	int		size;

	size = ft_strlen(s1);
	dup = malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		malloc_exit();
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == 0 || start >= ft_strlen(s))
		return (ft_strdup_sub("\0"));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start + len > ft_strlen(s))
		len--;
	str = (char *)malloc(len + 1);
	if (!str)
		malloc_exit();
	j = 0;
	while (j < len && start < ft_strlen(s))
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}
