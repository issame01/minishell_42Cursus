/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:22:13 by osabir            #+#    #+#             */
/*   Updated: 2023/08/05 04:00:26 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_clen(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	long	v;

	v = n;
	if (v == 0)
		return (ft_strdup("0"));
	j = ft_clen(v);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		malloc_exit();
	str[j] = '\0';
	j--;
	if (v < 0)
	{
		str[0] = '-';
		v *= -1;
	}
	while (v != 0)
	{
		str[j] = (v % 10) + '0';
		v /= 10;
		j--;
	}
	return (str);
}
