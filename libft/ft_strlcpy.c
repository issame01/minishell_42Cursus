/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:07:22 by osabir            #+#    #+#             */
/*   Updated: 2022/11/14 13:06:02 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	j;
	size_t	n;

	j = 0;
	n = ft_strlen(src);
	if (len <= 0)
		return (n);
	while (src[j] && j < (len - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (n);
}
