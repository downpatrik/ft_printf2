/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:50:20 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:22:28 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*ft_create_flag(char *str, va_list *p_ap)
{
	t_flag	*flag;

	if (ft_flag_get_key(str) == 0)
		return (NULL);
	if (!(flag = (t_flag *)ft_memalloc(sizeof(t_flag))))
		return (NULL);
	flag->key = ft_flag_get_key(str);
	flag->conv = str[ft_strlen(str) - 1];
	flag->length = flag->conv != 'U' ? ft_flag_get_length(str) : LENGTH_L;
	flag->minus = ft_flag_get_minus(str);
	if (flag->minus == 1)
		flag->zero = 0;
	else
		flag->zero = ft_flag_get_zero(str);
	flag->width = ft_flag_get_width(str, p_ap, flag);
	flag->precision = ft_flag_get_precision(str, p_ap);
	flag->plus = ft_flag_get_plus(str);
	flag->space = ft_flag_get_space(str);
	flag->hash = ft_flag_get_hash(str);
	flag->character = -1;
	flag->character_i = -1;
	flag->size_allocation = 0;
	return (flag);
}

int			ft_flag_get_space(char *flag)
{
	unsigned int	i;

	i = 0;
	if (flag[ft_strlen(flag) - 1] == '%')
		return (0);
	while (flag[i] && is_valid_conversion(flag[i]) == 0)
	{
		if (flag[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int			is_valid_conversion(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == 'f')
		return (1);
	return (0);
}

static int	is_valid_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
		return (1);
	return (0);
}

int			ft_flag_get_length(char *flag)
{
	size_t	i;

	i = 0;
	while (flag[i] && is_valid_conversion(flag[i]) == 0)
		i++;
	if (i-- > 1)
	{
		while (i > 0 && is_valid_length(flag[i]) == 0)
			i--;
		if (flag[i] == 'j')
			return (LENGTH_J);
		if (flag[i] == 'z')
			return (LENGTH_Z);
		if (flag[i] == 'h' && i > 1 && flag[i - 1] == 'h')
			return (LENGTH_HH);
		if (flag[i] == 'h')
			return (LENGTH_H);
		if (flag[i] == 'l' && i > 1 && flag[i - 1] == 'l')
			return (LENGTH_LL);
		if (flag[i] == 'l')
			return (LENGTH_L);
		if (flag[i] == 'L')
			return (LENGTH_L_MAJ);
	}
	return (0);
}
