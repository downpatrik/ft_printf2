/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:16 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:19:54 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nblen(long nb)
{
	size_t	nblen;

	nblen = 0;
	if (nb == 0)
		return (2);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	nblen++;
	return (nblen);
}

char			*ft_itoa_e(int nb)
{
	char	*output;
	size_t	nb_len;
	long	n;

	n = nb;
	nb_len = ft_nblen(n) + 1;
	if (!(output = (char *)ft_memalloc((nb_len + 4) * sizeof(char))))
		return (NULL);
	output[0] = 'e';
	output[1] = n < 0 ? '-' : '+';
	n = n < 0 ? -n : n;
	if (n < 10)
	{
		output[nb_len - 1] = '0';
		output[nb_len] = n + '0';
		output[nb_len + 1] = '\0';
		return (output);
	}
	output[nb_len] = '\0';
	while (n != 0)
	{
		output[--nb_len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}
