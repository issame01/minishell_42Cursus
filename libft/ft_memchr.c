/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:39:29 by osabir            #+#    #+#             */
/*   Updated: 2022/11/15 12:25:23 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			j;

	s1 = (unsigned char *)s;
	j = 0;
	while (j < n)
	{
		if (s1[j] == (unsigned char)c)
			return ((void *)(s + j));
		j++;
	}
	return (NULL);
}
