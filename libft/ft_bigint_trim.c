/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:53:53 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:32:28 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_bigint_trim_right(char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = len - 1;
	if (len == 0)
		return (str);
	while (str[i] && str[i] == '0')
	{
		str[i] = 0;
		i--;
	}
	return (str);
}

static char	*ft_bigint_trim_left(char *str)
{
	size_t	nb;
	size_t	i;
	size_t	len;

	nb = 0;
	len = ft_strlen(str);
	while (str[nb] && str[nb] == '0')
		nb++;
	if (nb == 0)
		return (str);
	i = 0;
	while (str[i] && i + nb <= len)
	{
		str[i] = str[i + nb];
		i++;
	}
	while (i != len)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char		*ft_bigint_trim(char *str)
{
	str = ft_bigint_trim_left(str);
	str = ft_bigint_trim_right(str);
	return (str);
}
