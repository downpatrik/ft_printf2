/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_to_allocate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:41 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:16:04 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	max(int a, int b, int c)
{
	int	result;

	result = a;
	if (b > result)
		result = b;
	if (c > result)
		result = c;
	return (result);
}

int			ft_len_to_alloc(size_t original_nblen, t_flag *flag)
{
	return (max((int)(original_nblen + 10), (int)(flag->width + 10),
							(int)(flag->precision + 10)));
}
