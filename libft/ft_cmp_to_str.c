/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:00:46 by osabir            #+#    #+#             */
/*   Updated: 2023/08/09 16:23:43 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmp_to_str(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (s1[0] == 0 && s2[0] == 0)
		return (1);
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			if (*(s1 + 1) == '\0' && *(s2 + 1) == '\0')
				return (1);
		}
		else if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
