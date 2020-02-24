/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:37 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:24:51 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_can_fill_to_the_left(t_flag *flag, int sign)
{
	(void)sign;
	return (flag->zero == 1 && flag->minus == 0);
}

int	ft_can_fill_to_the_right(t_flag *flag, int sign)
{
	return (!ft_can_fill_to_the_left(flag, sign));
}

int	ft_can_fill_with_zeros(t_flag *flag, int sign)
{
	return (ft_can_fill_to_the_left(flag, sign) && flag->precision == -1);
}

int	ft_can_fill_with_zeros_float(t_flag *flag, int sign)
{
	return (ft_can_fill_to_the_left(flag, sign));
}
