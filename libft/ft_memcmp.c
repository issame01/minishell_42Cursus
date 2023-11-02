/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:24:55 by osabir            #+#    #+#             */
/*   Updated: 2022/11/17 12:39:12 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			j;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	j = 0;
	while (j < n)
	{
		if (a1[j] != a2[j])
			return (a1[j] - a2[j]);
		j++;
	}
	return (0);
}
