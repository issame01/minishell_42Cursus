/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:50:03 by osabir            #+#    #+#             */
/*   Updated: 2022/11/20 12:03:14 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			j;

	b1 = (unsigned char *)dst;
	b2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (!b1 && !b2)
		return (NULL);
	j = 0;
	while (j < n)
	{
		b1[j] = b2[j];
		j++;
	}
	return (b1);
}
