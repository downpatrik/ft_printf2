/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:46 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:21:42 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_can_apply_plus(t_flag *flag, int sign)
{
	return (flag->plus == 1 && sign >= 0 && sign != 2);
}

int	ft_can_apply_space(t_flag *flag, int sign)
{
	return (flag->plus == 0 && flag->space == 1 && sign >= 0 && sign != 2);
}

int	ft_can_apply_prefix(t_flag *flag, int sign)
{
	if (flag->hash && sign != 0)
		return (1);
	if (sign == 0 && flag->precision == 0 && flag->conv == 'o' && (flag->hash))
		return (1);
	if (flag->key & KEY_P)
		return (1);
	return (0);
}

int	ft_can_apply_minus(t_flag *flag, int sign)
{
	(void)flag;
	return (sign < 0);
}
