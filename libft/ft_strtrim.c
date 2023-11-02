/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:06:28 by osabir            #+#    #+#             */
/*   Updated: 2023/07/26 17:00:00 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	char	*s;
	char	*s2;
	int		j;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	s = NULL;
	s2 = s1;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	j = ft_strlen(s1);
	while (j != 0 && ft_strchr(set, s1[j]))
		j--;
	if (s1 && s1[0] != '\0')
		s = ft_substr(s1, 0, j + 1);
	else
		return (free(s2), ft_strdup(""));
	free(s2);
	return (s);
}
