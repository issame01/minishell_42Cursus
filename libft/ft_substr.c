/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:33:35 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 04:01:18 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	if (start >= j)
		start = j;
	if (len > j - start)
		len = (j - start);
	str = malloc(len + 1);
	if (!str)
		malloc_exit();
	if (s)
	{
		while (i < len && s[start])
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
