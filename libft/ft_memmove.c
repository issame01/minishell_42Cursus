/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:04:03 by osabir            #+#    #+#             */
/*   Updated: 2022/11/17 16:33:22 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (!s1 && !s2)
		return (0);
	if (len == 0)
		return (s1);
	if (s1 > s2)
	{
		while (len > 0)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
		return (s1);
	}
	else
	{
		ft_memcpy(s1, s2, len);
	}
	return (s1);
}
