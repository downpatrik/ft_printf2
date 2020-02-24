/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:58 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:29:58 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_format_is_valid(const char *fo)
{
	int i;
	int ret;

	i = -1;
	while (fo[++i])
	{
		if (fo[i] == '%')
		{
			ret = (int)ft_flaglen(fo + i);
			if (ret == -1)
				return (0);
			i += ret;
		}
	}
	return (1);
}
