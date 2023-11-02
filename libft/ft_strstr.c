/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:39:07 by osabir            #+#    #+#             */
/*   Updated: 2023/06/18 15:39:37 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *need)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (need[0] == '\0')
		return ((char *)hay);
	if (need == 0)
		return ((char *)hay);
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == need[j])
		{
			if (need[j + 1] == '\0')
				return ((char *)&hay[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
