/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:05:13 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 04:00:18 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char *s1, char c)
{
	char	*str;
	int		j;
	int		o;

	if (!s1 || !c)
		return (NULL);
	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		malloc_exit();
	j = 0;
	o = 0;
	while (s1[j] != '\0')
		str[o++] = s1[j++];
	str[o++] = c;
	str[o] = '\0';
	free(s1);
	return (str);
}
