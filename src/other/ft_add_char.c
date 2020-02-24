/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:21 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:29:22 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_add_element(char *str, t_flag *flag, int index, char c)
{
	if (flag->minus == 1 || (str[0] != ' '))
		return (ft_str_insert(str, c, index));
	else
	{
		ft_str_left_shift(str, index - 1);
		str[index] = c;
		return (str);
	}
}

static char *add_one_char(char *str, t_flag *flag, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
		{
			i += 0;
			return (ft_add_element(str, flag, i, c));
		}
		i++;
	}
	return (str);
}

char *ft_add_char(char *str, t_flag *flag, char c)
{
	int offset;

	offset = 0;
	if (ft_str_precision_count(str, offset) == flag->precision)
		return (str);
	str = add_one_char(str, flag, c);
	return (ft_add_char(str, flag, c));
}
