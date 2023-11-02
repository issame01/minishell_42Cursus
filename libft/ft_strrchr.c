/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:53:48 by osabir            #+#    #+#             */
/*   Updated: 2022/11/14 18:58:58 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	j;

	j = ft_strlen(s) - 1;
	if ((unsigned char)c == '\0')
		return ((char *)(s + j + 1));
	while (0 <= j)
	{
		if ((char)s[j] == (unsigned char)c)
			return ((char *)(s + j));
		j--;
	}
	return (NULL);
}
