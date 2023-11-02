/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:38:58 by idryab            #+#    #+#             */
/*   Updated: 2023/08/05 03:57:24 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n--)
		*(s1++) = *(s2++);
	return (dest);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = malloc(1);
		if (!(s1))
			malloc_exit();
		s1[0] = 0;
	}
	if (s1 || s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		join = (char *)malloc(len1 + len2 + 1);
		if (!join)
			malloc_exit();
		ft_memcpy(join, s1, len1);
		ft_memcpy(join + len1, s2, len2 +1);
		return (join);
	}
	return (NULL);
}
