/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:42:12 by osabir            #+#    #+#             */
/*   Updated: 2023/06/18 15:42:31 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	while ((b1[i] || b2[i]))
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
