/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:58:32 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:08:36 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_precision_nb(char *str, t_flag *flag, int sign)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	if (sign == 0 && flag->precision == 0)
	{
		str = ft_strcpy(str, "");
		return (str);
	}
	if (flag->precision < 0)
		return (str);
	if (str_len == (unsigned int)flag->precision)
		return (str);
	if (ft_str_precision_count(str, 0) < flag->precision)
		return (ft_add_char(str, flag, '0'));
	return (str);
}

char	*ft_apply_precision_str(char *str, t_flag *flag, int sign)
{
	if (sign == 0 && flag->precision == 0)
		return (ft_strcpy(str, ""));
	if (flag->precision < 0)
		return (str);
	str[flag->precision] = '\0';
	return (str);
}
