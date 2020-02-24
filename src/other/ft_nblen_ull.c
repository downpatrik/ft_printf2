/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_ull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:33 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:16:15 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nblen_ull(unsigned long long nb)
{
	size_t	nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen);
}
