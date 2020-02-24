/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_pr_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:51:43 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:07:39 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_apply_wildcard(va_list *ap, t_flag *flag)
{
	long long	width;

	width = (long long)va_arg(*ap, int);
	if (width > 2147483647)
		return (0);
	if (width == 0)
	{
		flag->zero = 1;
		return (0);
	}
	if (width < 0)
	{
		flag->minus = 1;
		return ((int)(-1 * width));
	}
	return ((int)width);
}

static int	ft_get_width(char *str, int i, int wild, long long width_w)
{
	long long	width;

	width = 0;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		width = width * 10 + (str[i] - '0');
		i++;
	}
	if (wild)
		width = width > width_w ? width_w : width;
	if (width > 2147483647)
		return (0);
	return ((int)width);
}

int			ft_flag_get_width(char *str, va_list *ap, t_flag *flag)
{
	long long	width_wildcard;
	int			i;
	int			wild;

	i = 0;
	width_wildcard = 0;
	wild = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		if (str[i] == '*')
		{
			width_wildcard = ft_apply_wildcard(ap, flag);
			wild = 1;
		}
		else if (ft_isdigit(str[i]) == 1 && str[i] != '0')
			return (ft_get_width(str, i, wild, width_wildcard));
		i++;
	}
	return (width_wildcard);
}

static int	ft_get_precision(char *flag, int i)
{
	long long	precision;

	i++;
	precision = 0;
	while (flag[i] && ft_isdigit(flag[i]))
	{
		precision = precision * 10 + (flag[i] - '0');
		i++;
	}
	if (precision > 2147483647)
		return (-1);
	return ((int)precision);
}

int			ft_flag_get_precision(char *flag, va_list *ap)
{
	unsigned int	i;
	long long		precision;

	i = 0;
	precision = 0;
	while (flag[i])
	{
		if (flag[i] == '.' && flag[i + 1] && ft_isdigit(flag[i + 1]))
			return (ft_get_precision(flag, i));
		else if (flag[i] == '.' && flag[i + 1] == '*')
		{
			precision = (long long)va_arg(*ap, int);
			if (precision > 2147483647 || precision < 0)
				return (-1);
			return ((int)precision);
		}
		else if (flag[i] == '.')
			return (0);
		i++;
	}
	return (-1);
}
