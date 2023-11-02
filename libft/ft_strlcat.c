/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:17:39 by osabir            #+#    #+#             */
/*   Updated: 2022/11/17 16:35:59 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t len)
{
	size_t	ds;
	size_t	sr;
	size_t	j;
	size_t	i;

	if (len == 0)
		return (ft_strlen(src));
	ds = ft_strlen(dst);
	sr = ft_strlen(src);
	i = ds;
	j = 0;
	if (len < ds + 1)
		return (sr + len);
	while (src[j] != '\0' && i < len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ds + sr);
}
