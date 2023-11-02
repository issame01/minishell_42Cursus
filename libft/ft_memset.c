/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:08:19 by osabir            #+#    #+#             */
/*   Updated: 2022/11/17 16:34:56 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			j;

	str = (unsigned char *)b;
	j = 0;
	while (j < len)
	{
		str[j] = (unsigned char)c;
		j++;
	}
	return (str);
}
