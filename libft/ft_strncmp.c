/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:31:29 by osabir            #+#    #+#             */
/*   Updated: 2022/11/21 18:04:23 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			j;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	j = 0;
	while (j < n && (b1[j] || b2[j]))
	{
		if (b1[j] != b2[j])
			return (b1[j] - b2[j]);
		j++;
	}
	return (0);
}
