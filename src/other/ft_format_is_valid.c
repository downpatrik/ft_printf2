/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:58 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:20:37 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_is_valid(const char *fo)
{
	int	i;
	int	ret;

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
