/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaglen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:54 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:29:54 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int is_valid_par(char c)
{
	if (c == ' ' || c == '#' || c == '0' || c == '-' || c == '+' || c == '*' || c == '$' || c == '.')
		return (1);
	if (ft_isdigit(c) == 1)
		return (1);
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
		return (1);
	return (0);
}

size_t ft_flaglen(const char *str)
{
	size_t i;

	i = 1;
	while (str[i] && is_valid_par(str[i]) == 1)
	{
		if (str[i] == '%')
			break;
		i++;
	}
	return (i);
}
