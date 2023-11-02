/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:54:33 by osabir            #+#    #+#             */
/*   Updated: 2022/11/15 12:36:23 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (need[0] == '\0')
		return ((char *)hay);
	if (len == 0)
		return (NULL);
	if (need == 0)
		return ((char *)hay);
	while (i < len && hay[i])
	{
		j = 0;
		while ((i + j) < len && hay[i + j] == need[j])
		{
			if (need[j + 1] == '\0')
				return ((char *)&hay[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
