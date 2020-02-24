/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:31:04 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:15:08 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa_offset(unsigned long long nb, size_t size_allocation)
{
	char	*output;
	size_t	nb_len;

	nb_len = ft_nblen_ull(nb);
	if (!(output = (char *)ft_memalloc(sizeof(char) * size_allocation)))
		return (NULL);
	output[0] = '0';
	output[nb_len] = '\0';
	while (nb != 0)
	{
		output[--nb_len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (output);
}
