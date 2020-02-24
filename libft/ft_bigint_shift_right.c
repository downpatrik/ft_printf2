/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_shift_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:55:49 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:55:50 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_bigint_shift_right(char *str, size_t nb, size_t limit)
{
	size_t len;

	len = ft_strlen(str);
	if (len == 0 || nb <= 0)
		return (str);
	len = len + nb;
	if (len + 1 > limit)
		len = limit - 1;
	str[len + 1] = 0;
	while (len >= nb)
	{
		str[len] = str[len - nb];
		len--;
	}
	while (nb != 0)
	{
		str[nb - 1] = '0';
		nb--;
	}
	return (str);
}
